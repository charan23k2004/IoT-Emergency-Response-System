# 🚨 IoT Emergency Response System

> An IoT-based emergency monitoring system using **ESP8266 (NodeMCU)**, **DHT11**, **MQ-2**, **IR Sensor**, **ThingSpeak Cloud**, and a **real-time Web Dashboard** for hazard detection and remote monitoring.

![Platform](https://img.shields.io/badge/Platform-ESP8266-blue)
![Language](https://img.shields.io/badge/Language-Arduino-success)
![IoT](https://img.shields.io/badge/Technology-IoT-orange)
![Cloud](https://img.shields.io/badge/Cloud-ThingSpeak-brightgreen)
![License](https://img.shields.io/badge/License-MIT-green)

---

# 📖 Project Overview

The **IoT Emergency Response System** is designed to continuously monitor environmental conditions using multiple sensors connected to an **ESP8266 NodeMCU**.

The system detects hazardous situations such as:

- 🌡 High Temperature
- 💧 High Humidity
- 🔥 Smoke / Gas Leakage
- 👀 Object Detection

Whenever predefined thresholds are exceeded, the system immediately:

- Activates a **Buzzer**
- Turns on an **LED Warning**
- Uploads sensor data to **ThingSpeak**
- Displays live values on a Web Dashboard
- Supports remote monitoring over Wi-Fi

---

# ✨ Features

✅ Real-Time Temperature Monitoring

✅ Humidity Monitoring

✅ Smoke & Gas Detection

✅ IR-based Object Detection

✅ Automatic LED & Buzzer Alerts

✅ ThingSpeak Cloud Integration

✅ Live Web Dashboard

✅ Remote Monitoring

---

# 🛠 Hardware Components

| Component | Purpose |
|------------|---------|
| ESP8266 NodeMCU | Main Controller |
| DHT11 | Temperature & Humidity |
| MQ-2 | Smoke / Gas Detection |
| IR Sensor | Object Detection |
| LED | Visual Alert |
| Buzzer | Audio Alert |
| Breadboard & Jumper Wires | Circuit Connections |

---

# 💻 Software Stack

- Arduino IDE
- HTML
- CSS
- JavaScript
- ThingSpeak API
- ESP8266 Wi-Fi Library

---

# 🏗 System Architecture

```text
                DHT11
                   │
MQ-2 ──────────────┤
                   ▼
            ESP8266 NodeMCU
                   │
          Threshold Detection
          │                 │
          ▼                 ▼
     LED + Buzzer     ThingSpeak Cloud
                              │
                              ▼
                      Web Dashboard
                              │
                              ▼
                    Remote Monitoring
```

---

# 🔄 Workflow

```text
Start
   │
   ▼
Read Sensor Values
   │
   ▼
Threshold Check
   │
   ├── Safe
   │      │
   │      ▼
   │ Upload to ThingSpeak
   │
   └── Hazard Detected
          │
          ▼
 Activate LED & Buzzer
          │
          ▼
 Upload to ThingSpeak
          │
          ▼
 Update Dashboard
          │
          ▼
 Repeat
```

---

# 📂 Repository Structure

```
IoT-Emergency-Response-System
│
├── Arduino
├── Web-Dashboard
├── Documentation
├── Screenshots
├── README.md
├── LICENSE
└── .gitignore
```

---

# 🚀 Getting Started

## Clone the Repository

```bash
git clone https://github.com/charan23k2004/IoT-Emergency-Response-System.git
```

## Upload the Arduino Code

1. Install Arduino IDE.
2. Install the ESP8266 Board Package.
3. Install required libraries:
   - DHT Sensor Library
   - ESP8266WiFi
   - ESP8266HTTPClient
4. Update your:
   - Wi-Fi SSID
   - Password
   - ThingSpeak API Key
5. Upload the sketch to NodeMCU.

---

# 📊 Project Modules

- Sensor Data Acquisition
- Hazard Detection
- Alert Generation
- Cloud Data Logging
- Web Dashboard
- Remote Monitoring

---

# 🔮 Future Enhancements

- 📱 Android Application
- 🔔 Push Notifications
- 📡 MQTT Communication
- 🤖 AI-based Anomaly Detection
- ☁ Firebase Integration

---

# 👨‍💻 Team

- Charan K
- Naveen S S
- Sachin Karthik V
- Sivaraman S
- Vijayabaskar

---

# 📜 License

This project is licensed under the MIT License.

---

⭐ If you found this project useful, consider giving it a Star!
