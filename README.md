# smartcarparking
* Autonomous Car Parking Mechanism.
* Uses two arduinos: Arduino Mega(Master) and Arduino UNO(Slave).
* I2C between Arduino Uno and Mega.
* Arduino Mega is responsible for sending signals to different modules like LCD,LED,Keypad and other sub components.
* While Arduino Uno with CNC shield mounted on it first receives a character from Mega and rotates the motor as per rotation specification   given in the code.
* Once rotation of Stepper motor is complete control is sent back to Mega and the process repeats.
* User is allowed to have a sequence of 3 character code available in 4x4 keypad module.
* Indication of Parking slot being reserved or not is given by LEDs.
* Rotation of Motors lead to movement of a mechanical structure with platform that reaches to appropriate parking location as per slot       selected by the user.

