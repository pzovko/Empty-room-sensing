# Empty-room-sensing

[![Project Status: Unsupported – The project has reached a stable, usable state but the author(s) have ceased all work on it. A new maintainer may be desired.](https://www.repostatus.org/badges/latest/unsupported.svg)](https://www.repostatus.org/#unsupported)

The scope of this project was to use an ultrasound distance sensor as an indication for room occupation. When the room is empty the sensor will read a constant value, but if the value changes there is movement inside and this is indicating room occupation. This information is sent to another microcontroller over a Nordic NRF24L01 Radio.

## Features
- Ultrasound sensor measurements are done using interrupts for better performance
- Energy consumption is reduced 
