# Building a GamePad Arduino to S-function in Simulink
![](/src/cover.jpg)

### Sender
- Arduino Uno
- USB Shield 2.0
- Bluetooth Dongle with PS4 Controller

### Receiver
- Arduino Mega

# Process
#### 1. Connect Arduino Uno to Mega via I2C communication
| Uno | Mega |
| --- | --- |
| 5v  | 5v |
| GND | GND |
| A0 | 21 |
| A1 | 20 |
#### 2. On Sender -> Compile and Upload the "Sender.ino" file to Arduino Uno via Arduino IDE.
#### 3. On Reciever -> Build and Upload the "simulink_s_func.slx" file to Arduino Mega via Simulink.
#### 4. If more button is required, modify the arduino file and build s-function according to the template and video below.

### S-function Template from [Link](https://www.youtube.com/watch?v=0OClHIdCyDg)
![](/src/template.png)
