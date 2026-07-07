# Home-Automation-via-Bluetooth
📌 Overview

This project implements a Bluetooth-based Home Automation System using an ESP32 and a 4-channel relay module. The ESP32 uses its built-in Classic Bluetooth (Bluetooth Serial) to receive commands from an Android smartphone and control up to four electrical appliances wirelessly.

Users can pair their phone with the ESP32 and use a Bluetooth terminal application to turn individual appliances ON or OFF, or control all appliances simultaneously.

✨ Features
📱 Wireless appliance control using Bluetooth
⚡ Controls up to 4 appliances
🔌 Supports active-LOW relay modules
🎯 Individual ON/OFF control for each relay
🏠 ALL ON / ALL OFF commands
💻 Serial Monitor debugging support
🚀 Uses ESP32's built-in Bluetooth (no HC-05 module required)

🛠️ Hardware Requirements
ESP32 Development Board
4-Channel Relay Module
Breadboard (optional)
Jumper Wires
USB Cable
Android Smartphone with a Bluetooth Serial Terminal app
AC appliances (for testing with proper electrical safety)

🔌 Circuit Connections
Relay Channel	ESP32 GPIO	Example Appliance
Relay IN1	GPIO 5	Light
Relay IN2	GPIO 18	Fan
Relay IN3	GPIO 19	Plug / Socket 1
Relay IN4	GPIO 21	Plug / Socket 2
Relay Module Connections
VCC → 5V
GND → GND
Note: The program is configured for an active-LOW relay module, where:
LOW = Relay ON
HIGH = Relay OFF

📱 Bluetooth Configuration
Device Name:
ESP32_HomeAutomation
Pairing Steps
Upload the program to the ESP32.
Enable Bluetooth on your smartphone.
Search for the device named ESP32_HomeAutomation.
Pair with the device.
Open a Bluetooth Serial Terminal application.
Connect to the ESP32 and send commands.

📟 Bluetooth Commands
Command	Action
1A	Appliance 1 ON
1B	Appliance 1 OFF
2A	Appliance 2 ON
2B	Appliance 2 OFF
3A	Appliance 3 ON
3B	Appliance 3 OFF
4A	Appliance 4 ON
4B	Appliance 4 OFF
0A	Turn ALL Appliances ON
0B	Turn ALL Appliances OFF

📚 Software Requirements
Arduino IDE
ESP32 Board Package
BluetoothSerial Library (included with ESP32 Arduino core)

📂 Project Structure
Home-Automation-Bluetooth/
│
├── 3_Home_Automation_Bluetooth.ino
├── README.md
├── Circuit_Diagram.png      (Optional)
├── Images/                  (Optional)
├── Demo_Video.mp4           (Optional)

└── LICENSE
🚀 How to Run
Install the ESP32 board package in Arduino IDE.
Open 3_Home_Automation_Bluetooth.ino.
Select ESP32 Dev Module as the target board.
Connect the ESP32 using a USB cable.
Select the correct COM port.
Upload the code.
Open the Serial Monitor at 115200 baud.
Pair your smartphone with ESP32_HomeAutomation.
Connect using a Bluetooth Serial Terminal app and send commands to control the relays.

🔄 Working Principle
The ESP32 initializes Bluetooth with the device name ESP32_HomeAutomation.
The smartphone pairs with the ESP32 over Bluetooth.
The user sends text commands from the Bluetooth terminal.
The ESP32 interprets each command and switches the corresponding relay.
The relay controls the connected electrical appliance.
Status messages are displayed in both the Bluetooth terminal and the Arduino Serial Monitor.

💡 Future Improvements
Android mobile application with buttons
Voice-controlled home automation
Wi-Fi and IoT support
Google Assistant or Alexa integration
Scheduling and timer-based appliance control
Real-time appliance status monitoring

🎯 Learning Outcomes
ESP32 Bluetooth Serial communication
Relay interfacing
GPIO programming
Embedded C programming
Wireless home automation
Command-based device control
