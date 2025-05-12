# Traffic Light Controller Project 🚦

## 📚 Project Overview
This project implements a traffic light controller system using the STM32F103RB microcontroller, designed to manage a 4-way intersection. It includes features such as GPIO control for buttons and LEDs, state machine implementation, task scheduling, and I2C communication for 16x2 LCD display. The controller efficiently manages traffic flow, ensuring safe and smooth vehicle movement while providing real-time information display.

## ✨ Key Features
- GPIO configuration for buttons and LED control
- State machine-based traffic light logic
- Task scheduling for efficient traffic management
- I2C communication for 16x2 LCD display
- Modular code structure for easy maintenance and scalability
- Robust error handling and edge-case management

## 🛠️ Technologies Used
- STM32F103RB (ARM Cortex-M3)
- C/C++ for firmware development
- I2C protocol for LCD communication
- State machine for traffic light logic
- PWM and DMA for precise LED control
- Bash scripting for build automation

## 📁 Project Structure
```
Traffic_Light_Controller/
├── src/
│   ├── main.c
│   ├── traffic_light.c
│   ├── i2c_lcd.c
│   └── gpio_config.c
├── inc/
│   ├── traffic_light.h
│   ├── i2c_lcd.h
│   └── gpio_config.h
├── README.md
└── run.sh
```

## 🚀 Getting Started
### Prerequisites
- STM32CubeMX (optional for code generation)
- STM32CubeIDE or VS Code with ARM GCC toolchain
- USB to UART adapter (e.g., ST-Link V2)

### Setup Instructions
1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/Traffic_Light_Controller.git
   cd Traffic_Light_Controller
   ```
2. Build the project:
   ```bash
   ./run.sh
   ```
3. Flash the firmware to the STM32F103RB board.

## 📑 Usage
- Press the button to switch traffic light modes.
- Monitor the traffic light status on the 16x2 LCD display.

## 🤝 Contribution
Contributions, issues, and feature requests are welcome!

## 📄 License
This project is licensed under the MIT License.

## 📞 Contact
For more information, please contact: your-email@example.com
