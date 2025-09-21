<!doctype html>
<html lang="en">
<head>
  <meta charset="utf-8" />
  <title>Wireless Safety Control for Two-Wheeler — README</title>
  <meta name="viewport" content="width=device-width,initial-scale=1" />
  <style>
    body { font-family: Inter, system-ui, -apple-system, "Segoe UI", Roboto, "Helvetica Neue", Arial; line-height:1.6; padding:24px; color:#111; background:#f7f8fb; }
    .container { max-width:900px; margin:0 auto; background:#fff; padding:28px; border-radius:12px; box-shadow:0 6px 18px rgba(10,10,20,0.06); }
    h1 { margin:0 0 8px; font-size:28px; }
    p.lead { color:#444; margin-top:0; }
    .row { display:flex; gap:20px; flex-wrap:wrap; }
    .card { flex:1 1 300px; background:#fafafa; padding:14px; border-radius:8px; border:1px solid #eee; }
    ul { margin:0 0 12px 20px; }
    code { background:#eef2ff; padding:2px 6px; border-radius:4px; font-family:monospace; }
    a.btn { display:inline-block; margin-top:8px; padding:8px 12px; border-radius:8px; background:#0b63ff; color:#fff; text-decoration:none; }
    footer { margin-top:18px; color:#666; font-size:13px; }
  </style>
</head>
<body>
  <div class="container">
    <h1>Wireless Safety Control for Rider of Two-Wheeler</h1>
    <p class="lead">A student project implementing helmet detection, alcohol sensing, accident alerts (GSM/GPS), and engine-lock control to improve two-wheeler rider safety.</p>

    <div class="row">
      <div class="card">
        <h3>Project Overview</h3>
        <p>This system integrates sensors (alcohol sensor, eye-blink/drowsiness, gyro), RF/ESP/ATmega controllers, a GSM/GPS module and a servo based engine lock to enforce safety and send emergency alerts when needed.</p>
      </div>

      <div class="card">
        <h3>Highlights</h3>
        <ul>
          <li>Helmet detection and start-permission logic</li>
          <li>Alcohol detection to prevent ignition if intoxicated</li>
          <li>Crash detection + automatic SMS alerts with location (GSM/GPS)</li>
          <li>Servo/relay engine-lock for enforcement</li>
          <li>Data logging for monitoring and reporting</li>
        </ul>
      </div>
    </div>

    <h3>Files in this repository</h3>
    <ul>
      <li><strong>Source code</strong> — microcontroller sketches and wiring (check the <code>/src</code> or root folders)</li>
      <li><strong>Hardware</strong> — schematics, PCB layouts and BOM</li>
      <li><strong>Documentation</strong> — full project report (PDF)</li>
    </ul>

    <p>
      <a class="btn" href="./final%20report%20abhi.pdf" target="_blank" rel="noopener noreferrer">Open Project Report (PDF)</a>
    </p>

    <h3>How to run / test</h3>
    <ol>
      <li>Open the Arduino/ESP32 sketches in the Arduino IDE (or PlatformIO).</li>
      <li>Connect the required sensors and modules (SIM800L, MPU6050, alcohol sensor, servo, RF TX/RX).</li>
      <li>Configure GSM/APN and emergency contact number in the sketch before uploading.</li>
      <li>Upload the sketch to the corresponding microcontroller and test on a bench before vehicle integration.</li>
    </ol>

    <h3>Repository link</h3>
    <p>GitHub repo: <a href="https://github.com/Abhishekkhanai07/Wireless-Safety-Control-for-Two-Wheelers" target="_blank" rel="noopener noreferrer">github.com/Abhishekkhanai07/Wireless-Safety-Control-for-Two-Wheelers</a></p>

    <h3>Reference / Report</h3>
    <p>The full project report is included in this repository (PDF). For full design details, block diagrams, components, and results, open the PDF report linked above. :contentReference[oaicite:0]{index=0}</p>

    <h3>Contact</h3>
    <p>If you want to collaborate, suggest improvements, or report issues, open an issue on the repo or contact the author (as listed in the report).</p>

    <footer>
      <div>License: MIT (or choose your preferred license)</div>
      <div>Last updated: <!-- you can replace this with an actual date --> 2025-09-21</div>
    </footer>
  </div>
</body>
</html>
