char *indexPage = R"=====(
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <title>ESP8266</title>
  <style>
    :root {
      --bg-color: 228, 22%, 9%;
      --primary-color: 219, 100%, 61%;
      --danger-color: 0, 100%, 68%;
      --success-color: 134, 61%, 41%;
    }

    *, *::before, *::after {
      box-sizing: border-box;
    }

    * {
      margin: 0;
    }

    html, body {
      height: 100%;
    }

    body {
      line-height: 1.5;
      -webkit-font-smoothing: antialiased;
    }

    img, picture, video, canvas, svg {
      display: block;
      max-width: 100%;
    }

    input, button, textarea, select {
      font: inherit;
    }

    p, h1, h2, h3, h4, h5, h6 {
      overflow-wrap: break-word;
    }

    body {
      font-family: --apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Helvetica, Arial, sans-serif, "Apple Color Emoji", "Segoe UI Emoji", "Segoe UI Symbol";
      background-color: hsl(var(--bg-color));
      color: #fff;
    }

    .btn {
      display: inline-block;
      padding: 0.25rem 1rem;
      font-size: 1rem;
      line-height: 1.5;
      text-align: center;
      white-space: nowrap;
      vertical-align: middle;
      cursor: pointer;
      user-select: none;
      border: 1px solid transparent;
      border-radius: 0.25rem;
      background-color: transparent;
      transition: all 250ms ease 0s;
    }

    .btn-primary {
      color: #fff;
      background-color: hsl(var(--primary-color));
    }
    
    .btn-primary:hover {
      background-color: hsla(var(--primary-color), 0.65);
    }
    
    .btn-danger {
      color: #fff;
      background-color: hsl(var(--danger-color));
    }
    
    .btn-danger:hover {
      background-color: hsla(var(--danger-color), 0.65);
    }
    
    .bg-transparent {
      background: transparent !important;
    }

    .mt-2 {
      margin-top: 1rem;
    }

    .mb-2 {
      margin-bottom: 1rem;
    }

    input {
      max-width: 800px;
      width: 100%;
    }
    
    .loader {
      color: #ffffff;
      font-size: 20px;
      margin: 100px auto;
      width: 1em;
      height: 1em;
      border-radius: 50%;
      position: relative;
      text-indent: -9999em;
      -webkit-animation: load4 1.3s infinite linear;
      animation: load4 1.3s infinite linear;
      -webkit-transform: translateZ(0);
      -ms-transform: translateZ(0);
      transform: translateZ(0);
    }
    @-webkit-keyframes load4 {
      0%,
      100% {
        box-shadow: 0 -3em 0 0.2em, 2em -2em 0 0em, 3em 0 0 -1em, 2em 2em 0 -1em, 0 3em 0 -1em, -2em 2em 0 -1em, -3em 0 0 -1em, -2em -2em 0 0;
      }
      12.5% {
        box-shadow: 0 -3em 0 0, 2em -2em 0 0.2em, 3em 0 0 0, 2em 2em 0 -1em, 0 3em 0 -1em, -2em 2em 0 -1em, -3em 0 0 -1em, -2em -2em 0 -1em;
      }
      25% {
        box-shadow: 0 -3em 0 -0.5em, 2em -2em 0 0, 3em 0 0 0.2em, 2em 2em 0 0, 0 3em 0 -1em, -2em 2em 0 -1em, -3em 0 0 -1em, -2em -2em 0 -1em;
      }
      37.5% {
        box-shadow: 0 -3em 0 -1em, 2em -2em 0 -1em, 3em 0em 0 0, 2em 2em 0 0.2em, 0 3em 0 0em, -2em 2em 0 -1em, -3em 0em 0 -1em, -2em -2em 0 -1em;
      }
      50% {
        box-shadow: 0 -3em 0 -1em, 2em -2em 0 -1em, 3em 0 0 -1em, 2em 2em 0 0em, 0 3em 0 0.2em, -2em 2em 0 0, -3em 0em 0 -1em, -2em -2em 0 -1em;
      }
      62.5% {
        box-shadow: 0 -3em 0 -1em, 2em -2em 0 -1em, 3em 0 0 -1em, 2em 2em 0 -1em, 0 3em 0 0, -2em 2em 0 0.2em, -3em 0 0 0, -2em -2em 0 -1em;
      }
      75% {
        box-shadow: 0em -3em 0 -1em, 2em -2em 0 -1em, 3em 0em 0 -1em, 2em 2em 0 -1em, 0 3em 0 -1em, -2em 2em 0 0, -3em 0em 0 0.2em, -2em -2em 0 0;
      }
      87.5% {
        box-shadow: 0em -3em 0 0, 2em -2em 0 -1em, 3em 0 0 -1em, 2em 2em 0 -1em, 0 3em 0 -1em, -2em 2em 0 0, -3em 0em 0 0, -2em -2em 0 0.2em;
      }
    }
    @keyframes load4 {
      0%,
      100% {
        box-shadow: 0 -3em 0 0.2em, 2em -2em 0 0em, 3em 0 0 -1em, 2em 2em 0 -1em, 0 3em 0 -1em, -2em 2em 0 -1em, -3em 0 0 -1em, -2em -2em 0 0;
      }
      12.5% {
        box-shadow: 0 -3em 0 0, 2em -2em 0 0.2em, 3em 0 0 0, 2em 2em 0 -1em, 0 3em 0 -1em, -2em 2em 0 -1em, -3em 0 0 -1em, -2em -2em 0 -1em;
      }
      25% {
        box-shadow: 0 -3em 0 -0.5em, 2em -2em 0 0, 3em 0 0 0.2em, 2em 2em 0 0, 0 3em 0 -1em, -2em 2em 0 -1em, -3em 0 0 -1em, -2em -2em 0 -1em;
      }
      37.5% {
        box-shadow: 0 -3em 0 -1em, 2em -2em 0 -1em, 3em 0em 0 0, 2em 2em 0 0.2em, 0 3em 0 0em, -2em 2em 0 -1em, -3em 0em 0 -1em, -2em -2em 0 -1em;
      }
      50% {
        box-shadow: 0 -3em 0 -1em, 2em -2em 0 -1em, 3em 0 0 -1em, 2em 2em 0 0em, 0 3em 0 0.2em, -2em 2em 0 0, -3em 0em 0 -1em, -2em -2em 0 -1em;
      }
      62.5% {
        box-shadow: 0 -3em 0 -1em, 2em -2em 0 -1em, 3em 0 0 -1em, 2em 2em 0 -1em, 0 3em 0 0, -2em 2em 0 0.2em, -3em 0 0 0, -2em -2em 0 -1em;
      }
      75% {
        box-shadow: 0em -3em 0 -1em, 2em -2em 0 -1em, 3em 0em 0 -1em, 2em 2em 0 -1em, 0 3em 0 -1em, -2em 2em 0 0, -3em 0em 0 0.2em, -2em -2em 0 0;
      }
      87.5% {
        box-shadow: 0em -3em 0 0, 2em -2em 0 -1em, 3em 0 0 -1em, 2em 2em 0 -1em, 0 3em 0 -1em, -2em 2em 0 0, -3em 0em 0 0, -2em -2em 0 0.2em;
      }
    }
    
    .protect-screen {
      position: absolute;
      top: 0;
      left: 0;
      width: 100%;
      height: 100%;
      display: flex;
      justify-content: center;
      align-items: center;
      background: hlsa(var(--bg-color), 0.5);
      backdrop-filter: blur(5px) saturate(125%);
    }
    </style>
  <style>
    .coffee-hero {
      position: relative;
      background-image: url("https://images.pexels.com/photos/1254150/pexels-photo-1254150.jpeg?auto=compress&cs=tinysrgb&w=1260&h=750&dpr=1");
      background-size: cover;
      background-position: 0%;
      background-repeat: no-repeat;
      height: 40vh;
      overflow: hidden;
      isolation: isolate;
      display: flex;
      justify-content: center;
      align-items: center;
      border-bottom-left-radius: 1rem;
      border-bottom-right-radius: 1rem;
    }

    .coffee-hero h2 {
      text-align: center;
      font-size: max(18px, 2.5vmax);   
    }

    .coffee-hero::after {
      content: "";
      position: absolute;
      top: 0;
      left: 0;
      width: 100%;
      height: 100%;
      background-color: rgba(0, 0, 0, 0.5);
      z-index: -1;
    }

    .coffee-layout {
      display: grid;
      grid-gap: 1rem;
      padding-inline: 1rem;
      padding-block: 2rem;
    }
    
    .coffee-aside {
      height: 100%;
      display: grid;
      gap: 1rem;
    }

    .coffee-main {
      display: grid;
      background-color: hsla(0, 100%, 100%, 0.02);
      padding: 1rem;
      gap: 1rem;
      place-items: center;
    }
    
    .card-info {
      display: flex;
      width: 100%;
      flex-direction: column;
      background-color: hsla(0, 100%, 100%, 0.04);
      padding-inline: 3.5rem;
      padding-block: 1rem;
      justify-content: center;
      
    }
    
    .card-info-data {
      color: hsla(var(--primary-color), 0.8);
      display: inline-block;
      position: relative;
      text-align: center;
      margin-bottom: 0.25rem;
    }
    
    .card-info-data-value {
      font-size: 2.5rem;
      padding-right: 1.5rem;;
      padding-top: 5px;
    }
    
    .card-info-data-unit {
      position: absolute;
      top: -5px;
      margin-left: -1.25rem;
      font-size: 1.5rem;
      font-weight: 600;
    }
    
    .card-info-title {
      color: hsl(var(--primary-color));
      text-align: center;
      font-size: 1.15rem;
    }

    .state-roaster {
      height: min(1.5rem, 5vmax);
      width: min(1.5rem, 5vmax);
      border-radius: 50%;
      background-color: hsl(var(--primary-color));
    }

    .state-roaster.turn-off {
      background-color: hsl(var(--danger-color));
    }

    .state-roaster.turn-on {
      background-color: hsl(var(--success-color));
    }

    @media screen and (min-width: 768px) {
      .coffee-layout {
        grid-template-columns: 0.5fr 1.5fr;
      }

      .coffee-main {
        grid-template-columns: 1fr 1fr;
      }
    }
    </style>
</head>
<body>
  <div class="coffee-hero">
    <h2>Un buen tostado<br />hace un gran café</h2>
  </div>
  <div class="coffee-layout">
    <aside class="coffee-aside">
      <div class="card-info">
        <div class="card-info-data">
          <span id="value-temperature" class="card-info-data-value">0</span>
          <span class="card-info-data-unit">°C</span>
        </div>
        <h3 class="card-info-title">Temperatura</h3>
      </div>
      <div class="card-info">
        <div class="card-info-data">
          <span id="value-humidity" class="card-info-data-value">0</span>
          <span class="card-info-data-unit">%</span>
        </div>
        <h3 class="card-info-title">Humedad</h3>
      </div>
      <div class="card-info">
        <div class="card-info-data">
          <span id="value-time" class="card-info-data-value">0</span>
          <span class="card-info-data-unit">s</span>
        </div>
        <h3 class="card-info-title">Tiempo</h3>
      </div>
    </aside>
    <main class="coffee-main">
      <div style="display: flex; grid-column: 1/-1; justify-content: center;">
        <div id="state-roaster" style="margin-right: 0.5rem;" class="state-roaster turn-off"></div>
        <div id="state-roaster-text">
        Tostadora encendida
        </div>
      </div>
      <div class="card-info bg-transparent">
        <h3 class="card-info-title">Temperatura de cocción</h3>
        <div class="card-info-data mt-2">
          <span id="value-temperature-cook" class="card-info-data-value">130</span>
          <span class="card-info-data-unit">°C</span>
        </div>
        <input id="input-temperature-cook" class="mt-2" type="range" min="25" max="260" value="130" />
      </div>
      <div class="card-info bg-transparent">
        <h3 class="card-info-title">Tiempo de cocción</h3>
        <div class="card-info-data mt-2">
          <span id="value-time-cook" class="card-info-data-value">25</span>
          <span class="card-info-data-unit">min</span>
        </div>
        <input id="input-time-cook" class="mt-2" type="range" min="1" max="120" value="25"/>
      </div>
      <div style="display: flex; grid-column: 1/-1; justify-content: center;">
        <button id="btn-cook" class="btn btn-primary">Empezar cocción</button>
        <button id="btn-restart" style="display: none; margin-left: 1rem" class="btn btn-danger">Detener cocción</button>
      </div>
    </main>
  </div>
  <script>
    let socket
    let pauseOperation = false
    const protectScreen = document.createElement('div')
    protectScreen.classList.add('protect-screen')
    protectScreen.innerHTML = '<div class="loader"></div>'
    document.body.appendChild(protectScreen)

    const valueTemp = document.getElementById('value-temperature')
    const valueTime = document.getElementById('value-time')
    const valueHumidity = document.getElementById('value-humidity')
    const valueTempCook = document.getElementById('value-temperature-cook')
    const valueTimeCook = document.getElementById('value-time-cook')
    const inputTime = document.getElementById('input-time-cook')
    const inputTemp = document.getElementById('input-temperature-cook')
    const btnCook = document.getElementById('btn-cook')
    const btnPause = document.getElementById('btn-pause')
    const btnRestart = document.getElementById('btn-restart')
    const stateRoasterBadge = document.getElementById('state-roaster')
    const stateRoasterText = document.getElementById('state-roaster-text')

    const dataComponents = {
      temperature: 0,
      timeCook: 25,
      tempCook: 130,
      humidity: 0,
      stateRoaster: false
    }

    function connectSocket() {
      socket = new WebSocket(`ws://${window.location.hostname}:81/`)
    }

    connectSocket()

    socket.onopen = () => {
      document.body.removeChild(protectScreen)
      console.log('Socket Connect')
    }

    socket.onclose = () => {
      console.log('Socket Closed')
      setTimeout(connectSocket, 2000)
    }

    socket.onmessage = (event) => {
      const { title, data } = JSON.parse(event.data)

      if (title === 'components') {
        const { temperature, timeCook, tempCook, humidity, stateRoaster } = data
        if (temperature !== dataComponents['temperature']) {
          valueTemp.innerText = temperature
          dataComponents['temperature'] = temperature
        }
        if (humidity !== dataComponents['humidity']) {
          valueHumidity.innerText = humidity
          dataComponents['humidity'] = humidity
        }
        if (timeCook !== dataComponents['timeCook']) {
          valueTime.innerText = timeCook
          dataComponents['timeCook'] = timeCook
        }
        if (stateRoaster !== dataComponents['stateRoaster']) {
          if (stateRoaster) {
            btnCook.innerText = 'Pausar cocción'
            btnRestart.style.display = 'inline-block'
            dataComponents['stateRoaster'] = stateRoaster
            inputTemp.disabled = true
            inputTime.disabled = true
            stateRoasterBadge.classList.remove('turn-off')
            stateRoasterBadge.classList.add('turn-on')
            stateRoasterText.innerText = 'Tostadora encendida'
          } else {
            btnCook.innerText = 'Empezar cocción'
            btnRestart.style.display = 'none'
            dataComponents['stateRoaster'] = stateRoaster
            inputTemp.disabled = false
            inputTime.disabled = false
            stateRoasterBadge.classList.remove('turn-on')
            stateRoasterBadge.classList.add('turn-off')
            stateRoasterText.innerText = 'Tostadora apagada'
          }
        } 
 
        /*if (data['stateRoast'] === dataComponents['stateRoast']) valueTemp.innerText = data['stateRoast']*/
        //if (data['stateEngine'] === dataComponents['stateEngine']) valueTemp.innerText = data['']
      }
    }

    

    function handleMouseUpInput(e, title) {
      const { value } = e.target
      const data = JSON.stringify({
        title,
        data: parseInt(value)
      })
      socket.send(data)
    }

    function handleChangeInput(e, node) {
      const { value } = e.target
      node.innerText = value
    }
    
    function sendStateRoaster() {
      const data = JSON.stringify({
        title: 'StateRoaster',
        data: !dataComponents['stateRoaster']
      })
      socket.send(data)
    }

    
    inputTime.addEventListener('mouseup', (e) => handleMouseUpInput(e, 'TimeCook'))
    inputTemp.addEventListener('mouseup', (e) => handleMouseUpInput(e, 'TemperatureCook'))
    inputTime.addEventListener('input', (e) => handleChangeInput(e, valueTimeCook))
    inputTemp.addEventListener('input', (e) => handleChangeInput(e, valueTempCook))
    btnCook.addEventListener('click', sendStateRoaster)
    btnRestart.addEventListener('click', () => {
      sendStateRoaster();
      const data = JSON.stringify({
        title: 'TimeCook',
        data: inputTime.value
        })
      socket.send(data)
    })
  </script>
</body>
</html>
)=====";
