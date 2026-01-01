# Landmine Detector Robot 🤖

An Arduino-based landmine detection and obstacle avoidance robot designed to enhance safety by detecting buried metallic objects and avoiding obstacles autonomously.

---

## 📌 Project Overview

This project focuses on building a smart robotic system capable of:
- Detecting metallic objects (simulated landmines)
- Avoiding obstacles using ultrasonic sensing
- Alerting the user through buzzer and Bluetooth communication

The robot is built using Arduino and basic electronic components, making it a practical learning project combining **electronics, embedded systems, and robotics**.

---

## ✨ Features

- 🔍 Metal detection using metal detector sensor  
- 🚧 Obstacle detection and avoidance using ultrasonic sensor  
- 🔊 Buzzer alert when metal is detected  
- 📡 Bluetooth communication for status updates  
- 🔄 Servo-based scanning for better obstacle detection  
- 🚗 Motor control using L298N motor driver  

---

## 🧰 Hardware Components Used

- Arduino UNO  
- Metal Detector Sensor  
- Ultrasonic Sensor (HC-SR04)  
- L298N Motor Driver  
- DC Motors and Wheels  
- Servo Motor  
- Buzzer  
- Bluetooth Module (HC-05 / HC-06)  
- Battery Pack  
- Robot Chassis  

---

## ⚙️ How It Works

1. The robot continuously moves forward while scanning the path.
2. The ultrasonic sensor checks for obstacles ahead.
3. If an obstacle is detected, the servo rotates to scan alternate directions.
4. The robot changes direction to avoid the obstacle.
5. The metal detector sensor continuously checks for metallic objects.
6. When metal is detected:
   - The buzzer is activated
   - A signal is sent via Bluetooth
7. The robot alerts the user while maintaining safe navigation.

---
## 🎯 Learning Outcomes

- Gained hands-on experience with Arduino programming  
- Understood sensor integration and real-time decision making  
- Implemented motor control and obstacle avoidance logic  
- Learned basic Bluetooth communication for embedded systems  
- Improved hardware debugging and system integration skills

---
## 📂 Project Structure

landmine-detector-robot/
├── code/
│ └── landmine_detector_robot.ino
├── docs/
│ └── Project Report (PDF)
├── hardware/
│ └── Circuit Diagram
├── images/
│ └── Robot Build Images

---

## 📄 Documentation

Detailed project explanation, methodology, and results are available in the **docs/** folder.

---

## 👨‍💻 Author

**Yash Mohite**  
CSE (AIML) Student | Diploma in Electronics & Computer  
Exploring embedded systems, robotics, and emerging technologies.

---

## ⚠️ Disclaimer

This project is developed for **academic and educational purposes only**.  
It does not detect real landmines and should not be used in real-world hazardous environments.
