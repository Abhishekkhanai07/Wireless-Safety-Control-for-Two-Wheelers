<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8" />
    <title>🛵 Wireless Safety Control for Two-Wheelers</title>
</head>
<body>

<h1>🛵 Wireless Safety Control for Two-Wheelers</h1>

<p>
A <b>Smart Safety System</b> for two-wheeler riders that integrates 
<b>helmet detection, alcohol sensing, accident detection, GSM/GPS alerts, and engine locking</b> 
to reduce accidents and improve road safety.
</p>

<hr>

<h2>📄 Project Report</h2>
<p>
Read the detailed project report:  
<a href="Project Report.pdf" target="_blank">Open PDF Report</a>
</p>

<hr>

<h2>📌 Project Objective</h2>
<ul>
    <li>Ensure helmet usage before vehicle ignition</li>
    <li>Prevent drunk driving using alcohol detection</li>
    <li>Detect accidents and send emergency alerts with location</li>
    <li>Implement engine lock for safety enforcement</li>
    <li>Promote rider safety through smart monitoring</li>
</ul>

<hr>

<h2>🛠️ Tools & Technologies</h2>
<ul>
    <li>Microcontroller: Arduino / ATmega</li>
    <li>Sensors: Alcohol sensor, Eye-blink sensor, Gyroscope/Accelerometer</li>
    <li>Communication: RF module, GSM, GPS</li>
    <li>Actuator: Servo motor for engine lock</li>
    <li>Software: Arduino IDE, Proteus (simulation), Embedded C</li>
</ul>

<hr>

<h2>📂 Project Structure</h2>
<pre>
Wireless-Safety-Control-for-Two-Wheelers/
│── src/                  # Source code (Arduino sketches, embedded C)
│── hardware/             # Circuit diagrams, PCB layouts
│── final report abhi.pdf # Full project documentation
│── README.in             # Project documentation (HTML)
</pre>

<hr>

<h2>⚙️ Methodology</h2>
<ol>
    <li><b>Helmet Detection</b>
        <ul>
            <li>RF module checks if helmet is worn</li>
            <li>Ignition enabled only if helmet detected</li>
        </ul>
    </li>
    <li><b>Alcohol Sensing</b>
        <ul>
            <li>MQ-3 sensor detects alcohol level</li>
            <li>Engine disabled if intoxication detected</li>
        </ul>
    </li>
    <li><b>Accident Detection</b>
        <ul>
            <li>Gyroscope/accelerometer detects crash impact</li>
            <li>GPS + GSM sends alert SMS with location</li>
        </ul>
    </li>
    <li><b>Engine Lock</b>
        <ul>
            <li>Servo motor locks ignition in unsafe conditions</li>
        </ul>
    </li>
</ol>

<hr>

<h2>📌 Features</h2>
<ul>
    <li>Helmet verification before ignition</li>
    <li>Alcohol detection for drunk driving prevention</li>
    <li>Accident detection with automatic emergency alerts</li>
    <li>Engine lock system for enforcement</li>
    <li>GPS tracking with live location alerts</li>
</ul>

<hr>

<h2>🚀 How to Run / Test</h2>
<ol>
    <li>Clone the repository  
        <pre>git clone https://github.com/Abhishekkhanai07/Wireless-Safety-Control-for-Two-Wheelers.git</pre>
    </li>
    <li>Open Arduino IDE and load the sketches from <code>src/</code></li>
    <li>Connect sensors: MQ-3, RF module, MPU6050, GSM & GPS</li>
    <li>Configure GSM module with emergency contact number</li>
    <li>Upload the code to the microcontroller</li>
    <li>Test the system with helmet, alcohol sensor, and accident simulation</li>
</ol>

<hr>

<h2>🙋‍♂️ Author</h2>
<p>
<b>Abhishek Khanai</b><br>
B.E. in Electronics and Communication Engineering<br>
GitHub: <a href="https://github.com/Abhishekkhanai07">Abhishekkhanai07</a><br>
</p>

</body>
</html>
