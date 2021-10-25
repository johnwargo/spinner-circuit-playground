# Circuit Playground Spinner

This is a simple Circuit Python sketch that uses the device's two buttons to control the speed and direction of a single NeoPixel LED. 

Then the sketch initializes, it lights all NeoPixels green to show its ready to go. Next, the NeoPixels clear then the first NeoPixel lights in blue then starts moving around the device. 

Press the left button to change the speed (each button press slows it down until its been pushed 4 times). When you press the left button a fifth time, the speed resets to the default (100ms).

Press the right button to change the direction of the LED movement. The speed is reset every time the LEDs change direction.

