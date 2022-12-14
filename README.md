# Data Acquisition and Telemetry
Modelling the Data Acquisition and Telemetry system of a Formula Student based Electric Vehicle

### Flow of Data: (from Car to DAQ system)

<img src = "https://user-images.githubusercontent.com/89708853/205077056-9c784b63-8d18-4e65-806c-5a3a728bf2c8.png" width=60% height=60%>

<li>Each slave and master in the above diagram is a microcontroller (Arduino used for testing purposes).
<li>The Slave microcontrollers collect data from the sensors and send them over to the Master microcontroller via the CAN bus.
<li>The data then goes from the Master to the Storage and Display (Telemetry) Unit.
<br><br>
  
  
### Telemetry Dashboard: (Web Application on Node-RED)

<img src = "https://user-images.githubusercontent.com/89708853/205077760-2a8cec09-2499-4d87-981b-94a1b66e06fb.jpeg" width=60% height=60%>
