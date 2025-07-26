Smart Waste Segregation System
📌 Overview
It's a Smart Waste Segregation System capable of automatically classifying and segregating wastes into three types:

🪵 Dry Waste

🌧 Wet Waste

🧲 Metal Waste

An IR sensor, soil moisture sensor, and inductive proximity sensor are used along with a servo motor, stepper motor, and buzzer in this waste segregation system.

🧰 Components Used
Component	Quantity
Arduino Uno / Nano	1
IR Sensor	1
Inductive Proximity Sensor	1
Soil Moisture Sensor	1
Servo Motor (SG90/MG996R)	1
Stepper Motor (28BYJ-48) + ULN2003 Driver	1
Buzzer	1
Potentiometer (for soil input)	1
Connecting Wires	-
Breadboard	1
Power Supply (5V)	1

🧠 Working Principle
Metal Detection:

If metal is detected by the inductive proximity sensor, the stepper motor rotates the platform towards the metal bin.

The servo motor is then used to open the bin and drop the waste. 

The platform resets back to its original position after that.

Waste Detection via IR Sensor:

When the IR sensor detects waste, the soil moisture sensor checks the moisture content.

If moisture > 20%, it is wet waste.

Stepper motor rotates to wet bin, servo opens, waste is dropped.Smart Waste Segregation System
📌 Overview
It's a Smart Waste Segregation System capable of automatically classifying and segregating wastes into three types:

🪵 Dry Waste

🌧 Wet Waste

🧲 Metal Waste

An IR sensor, soil moisture sensor, and inductive proximity sensor are used along with a servo motor, stepper motor, and buzzer in this waste segregation system.

🧰 Components Used
Component	Quantity
Arduino Uno / Nano	1
IR Sensor	1
Inductive Proximity Sensor	1
Soil Moisture Sensor	1
Servo Motor (SG90/MG996R)	1
Stepper Motor (28BYJ-48) + ULN2003 Driver	1
Buzzer	1
Potentiometer (for soil input)	1
Connecting Wires	-
Breadboard	1
Power Supply (5V)	1

🧠 Working Principle
Metal Detection:

If metal is detected by the inductive proximity sensor, the stepper motor rotates the platform towards the metal bin.

The servo motor is then used to open the bin and drop the waste. 

The platform resets back to its original position after that.

Waste Detection via IR Sensor:

When the IR sensor detects waste, the soil moisture sensor checks the moisture content.

If moisture > 20%, it is wet waste.

Stepper motor rotates to wet bin, servo opens, waste is dropped.

If moisture ≤ 20%, it is considered as a dry waste.

The servo opens directly over the dry bin without any rotation.

Feedback:

A buzzer provides audible feedback for each detection and segregation event.

The Serial Monitor displays live status messages (helpful for debugging).

⚙ Pin Configuration
Component	Arduino Pin
IR Sensor	D5
Proximity Sensor	D6
Buzzer	D12
Soil Moisture (Analog)	A0
Servo Motor	D7
Stepper Motor IN1-IN4	D8 - D11

🔄 Sensor Threshold Calibration
Soil sensor readings map from 485 (wet) to 1023 (dry).

Moisture threshold: > 20% is Wet, else Dry.

Proximity sensor returns LOW (0) on detecting metal (adjust if inverted).

📦 How to Run
Upload the code to the Arduino using Arduino IDE.

Open Serial Monitor (9600 baud) for viewing the live readings and debug messages.

Place different types of wastes in front of the sensors.

Now watch as the wastes are segregated automatically according to type.

Future Improvements
Add a live display with LCD or OLED.

Connect it with IoT (e.g., Blynk or ThingSpeak) for remote monitoring.

Add control or reporting via mobile application.

Advanced waste detection using ML Image Classification.

👨‍💻 Developed By
Members:SHIYAM, YAZHINI, SUPRIYA, PRABHAKARAN

Institution:KPR INSTITUTE OF ENGINEERING AND TECHNOLOGY

Project Title: Smart Waste Segregation System
-------------------------------------------------

Smart Garbage Monitoring System via IoT and ESP32
📌 Overview
The IoT-based system, known as Smart Garbage Level Monitoring System, makes inferences of levels of wastes inside 2 dustbins using ultrasonic sensors. The data level is shown on the LCD screen, with the help of LEDs, and it is pushed to ThingSpeak cloud for viewership in real-time through the internet.

📷 Hardware Components
Component	Quantity	Purpose
ESP32 WiFi Module	1	Microcontroller with Wi-Fi
Ultrasonic Sensor (HC-SR04)	2	Distance measurement for dustbins
I2C LCD Display (16x2)	1	Shows live garbage levels
LEDs (Green & Red)	4	Status indication (Full/Empty)
Jumper Wires	-	Connections
Breadboard / PCB	1	Circuit connection (optional)
5V Power Supply	1	ESP32 and sensor power source

🧠 Features
📡 Real-time Garbage Level Measurement using Ultrasonic Sensors

💡 LED Indications:

Red LED ON → Dustbin is Full

Green LED ON → Dustbin is Empty

📺 Live data display on LCD (16x2 I2C)

☁ Live data logging to ThingSpeak IoT Cloud

📶 Internet connectivity via Wi-Fi (ESP32)

📁 Folder Structure
bash
Copy
Edit
SmartGarbageMonitoring/
├── images/                  # Hardware and prototype images
├── SmartGarbage.ino         # Main Arduino code
├── README.md                # This file
└── WiringDiagram.jpg        # (Optional) Wiring diagram
🔌 Pin Connections
ESP32 Pin	Connected Component
GPIO 4	TRIG1 (Dustbin 1)
GPIO 5	ECHO1 (Dustbin 1)
GPIO 18	TRIG2 (Dustbin 2)
GPIO 19	ECHO2 (Dustbin 2)
GPIO 12	GREEN_LED1
GPIO 14	RED_LED1
GPIO 26	GREEN_LED2
GPIO 27	RED_LED2
SDA (GPIO 21)	LCD I2C SDA
SCL (GPIO 22)	LCD I2C SCL

🌐 ThingSpeak Setup
Go to ThingSpeak.com

Create a free account.

Create a new channel with  Field 1: Distance1 (Dustbin 1)  Field 2: Distance2 (Dustbin 2)

Copy your Write API Key and paste it into the code:

cpp
Copy
Edit
const char* apiKey = "YOUR_API_KEY_HERE";
Upload the code and see your data live on your ThingSpeak channel.

🔧 How It Works
The ESP32 triggers ultrasonic sensors to measure distance (bin fill level).

Values are displayed on the LCD.

Based on threshold (e.g., <15 cm → full), LEDs are turned ON.

Data are sent to ThingSpeak every 15 seconds.

It allows remote monitoring of bin status.
🧑‍🤝‍🧑 Members of the Team are
Shiyam
Yazhini
Supriya
Prabakaran
👨‍🏫 Project Coordinator: Mr. Soundarajan

🏁 Future Improvements
Add Blynk/Firebase for app integration

SMS or email alerts for bin full status

Solar-powered ESP system

Add more bins & location tracking (GPS)

🧪 Sample Output (from Serial Monitor)
Dustbin 1: 12.3 cm, Dustbin 2: 22.1 cm
ThingSpeak Response: 200
📜 License
This project is developed for academic purposes and is open for enhancement.
