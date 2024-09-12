# Smart Alarm Clock with FreeRTOS

This project involves the development of a smart alarm clock using FreeRTOS. The alarm clock is designed to provide advanced features such as multiple alarms, snooze functionality, and real-time clock management.

## Architecture

### System Design
<img src="./assets/Desing Alarm System.png" alt="Alarm System Design" width="80%"/>

### Dependencies Diagram
<img src="./assets/Dependencies Diagram.png" alt="Dependencies Diagram" width="50%"/>

#### Components:
- **Main**: The main file that contains the setup and tasks initialization.
- **Services**: The header file that references the implementation of the services and the FreeRTOS tasks.
- **FreeRTOS**: The FreeRTOS library that provides the real-time operating system for the project.
- **LCD**: The LCD library that provides the display functionalities.4
- **PIR Sensor**: The PIR sensor library that provides the motion detection functionalities.
- **Real-Time Clock**: The RTC library that provides the real-time clock functionalities.
- **Noise Sensor**: The noise sensor library that provides the noise detection functionalities.
- **Rings**: The ring library that provides the sound functionalities.
- **Pins**: The pins library that provides the pin configurations.

#### The file structure of the project is as follows:
```

├── Assets
│   ...
├── Main
│   ├── main.ino
    ├── libs
        ├── FreeRTOS source files (Kernel)
        ├── LCD 
        ├── Noise Sensor
        ├── PIR Sensor
        ├── Real-Time Clock
        ├── Rings
        ├── Pins
        ├── Services
```
### FreeRTOS Integration
The FreeRTOS library was added to this project by copying the kernel content from the [official repository](https://github.com/FreeRTOS/FreeRTOS-Kernel).


## Current Features
- **Alarm Clock**: The system has an alarm clock that can be set in the code (for now) and when the time comes, the system will ring a sound.
- **Stop alarm**: The user can stop the alarm by pressing a button.
- **Dinamic ring sound adjustment**: The system read the enviroment noise and adjust the ring sound to be heard by the user.
- **Snooze functionality**: When the alarm rings, the system read the enviroment moviment and if the user is moving, the alarm will snooze for 5 minutes.

## Next Features
- **User interface**: The system will have a user web interface to set the alarm clock. The web app will connect to the system using the firebase API.
- **Real-time clock management**: The system can set the current time and date using the user interface.
- **Multiple alarm settings**: The user can set multiple alarms with different times and days of the week and rename them.



## Prototyping and Materials



## Contributing
Contributions are welcome!


## License
This project is licensed under the MIT License. See the `LICENSE` file for more details.


