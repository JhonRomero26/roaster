#include "ArduinoJson.h"
#include "ESP8266WiFi.h"
#include "ESP8266WebServer.h"
#include "WebSocketsServer.h"
#include "DHT.h"
#include "max6675.h"

#include "Arduino.h"
#include "webpages.h"

const char *ssid = "Romero";
const char *pass = "romero1972";

#define DHTTYPE DHT11
#define DHTPIN 14

const int thermoSO = 16;
const int thermoCS = 5;
const int thermoSCK = 4;

const int relay_engine = 13;
const int relay_resistances = 12;

StaticJsonDocument<200> responseJson;
StaticJsonDocument<200> requestJson;

WebSocketsServer webSocket = WebSocketsServer(81);
ESP8266WebServer server(80);
MAX6675 thermocouple(thermoSCK, thermoCS, thermoSO);
DHT dht = DHT(DHTPIN, DHTTYPE);

String json, oldJson;
float temperature = 0;
float humidity = 0;
int temperatureCook = 130;
int timeCook = 1500;
bool stateRoaster = false;


void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
  switch (type) {
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", num);
      break;
    case WStype_CONNECTED:
      {
        IPAddress ip = webSocket.remoteIP(num);
        Serial.printf("[%u] Connected from %d.%d.%d.%d\n", num, ip[0], ip[1], ip[2], ip[3]);
      }
      break;
    case WStype_TEXT:
      deserializeJson(requestJson, (char *)payload);
      String title = requestJson["title"];

      if (title == "TimeCook") {
        timeCook = requestJson["data"].as<signed int>() * 60;
      } else if (title == "TemperatureCook") {
        temperatureCook = requestJson["data"].as<signed int>();
      } else if (title == "StateRoaster") {
        stateRoaster = requestJson["data"].as<bool>();
        if (requestJson["data"].as<bool>()) {
          digitalWrite(relay_engine, HIGH);
          digitalWrite(relay_resistances, HIGH);
        } else {
          digitalWrite(relay_engine, LOW);
          digitalWrite(relay_resistances, LOW);
        }
      }
      break;
  }
}


void handleRoot() {
  server.send(200, "text/html", indexPage);
}


void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  dht.begin();

  pinMode(relay_engine, OUTPUT);
  pinMode(relay_resistances, OUTPUT);
  
  Serial.println("");
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}

void loop() {
  webSocket.loop();
  server.handleClient();

  temperature = thermocouple.readCelsius();
  humidity = dht.readHumidity();
 
  json = "";
  responseJson["title"] = "components";
  responseJson["data"]["temperature"] = temperature;
  responseJson["data"]["timeCook"] = timeCook;
  responseJson["data"]["temperatureCook"] = temperatureCook;
  responseJson["data"]["humidity"] = humidity;
  responseJson["data"]["stateRoaster"] = stateRoaster;
  serializeJson(responseJson, json);

  if (stateRoaster) {
    if (temperature >= temperatureCook && digitalRead(relay_resistances) == HIGH) {
      digitalWrite(relay_resistances, LOW);
    } else if (temperature <= temperatureCook - 15 && digitalRead(relay_engine) == LOW) {
      digitalWrite(relay_resistances, HIGH);
    }

    if (timeCook > 0) {
      timeCook--;
    } else {
      digitalWrite(relay_engine, LOW);
      digitalWrite(relay_resistances, LOW);
    }
  }

  if (json != oldJson) {
    webSocket.broadcastTXT(json);
  }

  oldJson = json;

  delay(1000);
}

