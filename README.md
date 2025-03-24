Car Black Box Using PIC18F4580
## Overview
Developed an embedded system for a Vehicle Dashboard and Event Logging System with real-time event capture and logging.

## Features

- **Default Screen Interface:** Displays current time, vehicle speed, and latest event on an LCD interfaced via I2C.
- **Menu-Driven Interface:** Options to View Log and Set Time, navigable via UP/DOWN keys with long-press actions.
- **Real-Time Event Logging:** Captures event details, including event signature, timestamp, and vehicle speed.
- **Persistent Event Storage:** Stores logs in external EEPROM for non-volatile retention and retrieval.
- **Log Viewing:** Allows users to scroll through indexed events while ensuring real-time event capture.
- **Gear Shifting Functionality:** Enables smooth gear selection via matrix keypad input.

## Technologies Used
- **Microcontroller:** Embedded system-based implementation
- **Display:** LCD (I2C interface)
- **Storage:** External EEPROM
- **Input:** Matrix Keypad
- **Programming Language:** C

## Usage
This system is designed for vehicle dashboards, enabling real-time event monitoring, secure user authentication, and efficient event storage.

## Future Enhancements
- Integration with CAN for enhanced vehicle data communication
- Wireless data transmission for remote monitoring
- Enhanced UI with touchscreen display support

