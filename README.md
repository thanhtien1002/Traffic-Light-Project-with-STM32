# Traffic Light Controller Project 🚦

## 📚 Project Overview
This project implements a traffic light controller system using the STM32F103RB microcontroller, designed to manage a 4-way intersection. It includes features such as GPIO control for buttons and LEDs, state machine implementation, task scheduling, and I2C communication for 16x2 LCD display. The controller efficiently manages traffic flow, ensuring safe and smooth vehicle movement while providing information display.

## ✨ Key Features
- GPIO configuration for buttons and LED control
- State machine-based traffic light logic
- Task scheduling for efficient traffic management
- I2C communication for 16x2 LCD display
- Modular code structure for easy maintenance and scalability

## 🛠️ Technologies Used
- STM32F103RB (ARM Cortex-M3)
- C/C++ for firmware development
- I2C protocol for LCD communication
- State machine for traffic light logic

## 📁 Project Structure
```
Traffic_Light_Controller/
├── src/
│   ├── main.c
│   ├── button.c
│   ├── fsm_automatic.c
|   ├── fsm_manual.c
|   ├── global.c
│   ├── lcd.c
|   ├── run_task.c
|   ├── scheduler.c
│   └── traffic_light.c
|   
├── inc/
|   ├── main.h
│   ├── button.h
│   ├── fsm_automatic.h
|   ├── fsm_manual.h
|   ├── global.h
│   ├── lcd.h
|   ├── run_task.h
|   ├── scheduler.h
│   └── traffic_light.h
├── README.md
```

## 🚀 Getting Started
### Prerequisites
- STM32CubeIDE
- USB to UART adapter (e.g., ST-Link V2)

### Setup Instructions
1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/Traffic_Light_Controller.git
   cd Traffic_Light_Controller

## 📑 Usage
- Press the button to switch traffic light modes.
- Monitor the traffic light status on the 16x2 LCD display.

## 🤝 Contribution
Contributions, issues, and feature requests are welcome!

## 📄 License
This project is licensed under the MIT License.

## 📞 Contact
For more information, please contact: caothanhtien2004@gmail.com
