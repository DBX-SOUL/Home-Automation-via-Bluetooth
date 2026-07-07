/*
  HOME AUTOMATION VIA BLUETOOTH - ESP32
  ----------------------------------------
  Uses the ESP32's built-in Classic Bluetooth (BluetoothSerial) to
  control 4 relay-driven appliances from a phone app such as
  "Serial Bluetooth Terminal" (Android) or any BLE/SPP terminal app.

  WIRING (assuming an active-LOW 4-channel relay module):
    Relay IN1 -> GPIO 5   (Appliance 1, e.g. Light)
    Relay IN2 -> GPIO 18  (Appliance 2, e.g. Fan)
    Relay IN3 -> GPIO 19  (Appliance 3, e.g. Plug 1)
    Relay IN4 -> GPIO 21  (Appliance 4, e.g. Plug 2)
    Relay VCC -> 5V, Relay GND -> GND

  COMMANDS (send as plain text over Bluetooth):
    1A = Appliance 1 ON     1B = Appliance 1 OFF
    2A = Appliance 2 ON     2B = Appliance 2 OFF
    3A = Appliance 3 ON     3B = Appliance 3 OFF
    4A = Appliance 4 ON     4B = Appliance 4 OFF
    0A = ALL ON             0B = ALL OFF

  PAIRING: Search for Bluetooth device named "ESP32_HomeAutomation"
  on your phone, pair it, then open it in a serial Bluetooth terminal app.
*/

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Enable it in "Tools -> Partition Scheme" or check your board config.
#endif

BluetoothSerial SerialBT;

const int RELAY_PINS[4] = {5, 18, 19, 21};
// Set to true if your relay module is "active LOW" (most common),
// meaning LOW = relay ON, HIGH = relay OFF
const bool ACTIVE_LOW = true;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_HomeAutomation");
  Serial.println("Bluetooth started. Pair with 'ESP32_HomeAutomation'.");

  for (int i = 0; i < 4; i++) {
    pinMode(RELAY_PINS[i], OUTPUT);
    setRelay(i, false); // start with everything OFF
  }
}

void loop() {
  if (SerialBT.available()) {
    String cmd = SerialBT.readStringUntil('\n');
    cmd.trim();
    cmd.toUpperCase();
    processCommand(cmd);
  }
}

void processCommand(String cmd) {
  if (cmd.length() < 2) return;

  char applianceChar = cmd.charAt(0);
  char stateChar = cmd.charAt(1);
  bool turnOn = (stateChar == 'A');

  if (applianceChar == '0') {
    // ALL appliances
    for (int i = 0; i < 4; i++) setRelay(i, turnOn);
    SerialBT.println(turnOn ? "ALL ON" : "ALL OFF");
    return;
  }

  int index = applianceChar - '1'; // '1'-'4' -> 0-3
  if (index >= 0 && index < 4) {
    setRelay(index, turnOn);
    SerialBT.print("Appliance ");
    SerialBT.print(index + 1);
    SerialBT.println(turnOn ? " ON" : " OFF");
  } else {
    SerialBT.println("Unknown command. Use e.g. 1A, 2B, 0A, 0B");
  }
}

void setRelay(int index, bool on) {
  bool level = ACTIVE_LOW ? !on : on;
  digitalWrite(RELAY_PINS[index], level);
  Serial.print("Relay ");
  Serial.print(index + 1);
  Serial.println(on ? " -> ON" : " -> OFF");
}
