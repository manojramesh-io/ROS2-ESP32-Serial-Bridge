# ESP32 Motor Controller

This code turns an esp32 into a Closed-loop motor controller!
It provides a simple serial interface to communicate with a high-level computer (e.g. running ROS2) and generates the appropriate PWM signals for a motor driver to drive two motors in the closed loop.

This is a fork of the original code, with some changes, and removal of the ROS nodes (see [this repo](https://github.com/joshnewans/ros_arduino_bridge) for an alternative). 

As I only require a subset of the functionality, I have no idea what does and doesn't work, beyond what is detailed below.
Feedback/improvements are welcome (though no promises on how quickly I'll respond). 
I only use the Motor drivers with 1 Direction Pin(INA) and 1 PWM(ENABLE) pin and the custom encoder puls reader.

TODO
- Finish this README


## Functionality

- The main functionality is receiving motor speed requests over a serial connection, and providing encoder feedback.
- Additionally, a function was added to use specific PID coefficients for each motor.
  
The original code has provisions for other features - e.g. read/write of digital/analog pins, and servo control, but I've never used them.

The main commands to know are

- `e` - Motor responds with current encoder counts for each motor
- `r` - Reset encoder values
- `o <PWM1> <PWM2>` - Set the raw PWM speed of each motor (-255 to 255)
- `m <Spd1> <Spd2>` - Set the closed-loop speed of each motor in *counts per loop* (Default loop rate is 30, so `(counts per sec)/30`)
- `p <Kp> <Kd> <Ki> <Ko>` - Update the PID parameters


## Gotchas

Some quick things to note

- There is an auto timeout (default 2s) so you need to keep sending commands for it to keep moving
- PID parameter order is PDI (?)
- Motor speed is in counts per loop
- Default baud rate 115200
- Needs carriage return (CR)
- Make sure serial is enabled (user in dial-out group)
- Check out the original through link


## TODO (maybe)
- Document PID tuning
- Add/test more driver boards (e.g. L298N)
- Add/test other functionality 
