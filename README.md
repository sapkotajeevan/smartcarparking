# Smart Car Parking Project
A Robust Car Parking System with an Autonomous Mechanical Structure that does a precise 2D movement to park vehicle in an appropriate parking slot. 

# Circuit Design
![image](https://github.com/jinmax100/smartcarparking/assets/51187747/6cf5993b-5d7e-41cf-92f6-476da00fd954)

# System Information
* [Arduino Mega 2560](https://store.arduino.cc/products/arduino-mega-2560-rev3) as a main control unit running mega_code_serial.ino
* [Arduino Uno](https://store.arduino.cc/products/arduino-uno-rev3) running uno_code.ino communicates with Arduino Mega via I2C channel, and provides step signals to motor drivers
* X and Y [Stepper Motors](https://www.elprocus.com/stepper-motor-types-advantages-applications/) to provide 2D Structual Movement.
* User Interface Panel contains [Matrix Keypad](https://www.electroduino.com/4x4-keypad-module/) allowing user to register Code Sequences, and [16x2 LCD Panel](https://www.electronicsforu.com/technology-trends/learn-electronics/16x2-lcd-pinout-diagram) to display relevant outputs.

# Mechanical Structure and User Interface Panel
<img src="https://user-images.githubusercontent.com/51187747/69154822-ce7a8000-0b08-11ea-9192-e4c5c9f24f7d.jpg" widdth="630" height="630">

*Note: The system has been enhanced to integrate different features not limited to 3D Structural Movement, Reservation Parking, etc. in [Multilayered Car Parking Project](https://github.com/sapkotajeevan/multilayeredcarparking) *

# Authors
* [Jeevan Sapkota](https://github.com/jinmax100) (Project Lead)
* Dipesh Dhamala (Project Memmber)
* Kailash Shrestha (Project Member)
* Jyoti KC (Project Member)


# LICENSE
[License Terms](https://github.com/jinmax100/smartcarparking/blob/master/LICENSE)


