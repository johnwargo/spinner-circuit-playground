# Circuit Playground Spinner

I recently joined Oracle as a product manager and discovered the [Oracle Education Foundation](https://oraclefoundation.org/index.html) and quickly volunteered to help in their Hello Circuit Playground program. The program uses the [Adafruit Circuit Playground](https://learn.adafruit.com/introducing-circuit-playground/overview) to help teach high school students Design Thinking and microcontroller-based project development. One of our prep assignments was to build something using the Circuit Playground and this is the project I came up with. 

## Operation

When the sketch initializes, it lights all NeoPixels green to show its ready to go (and that all LEDs function). Next, the sketch lights up one of the Circuit Playground's LEDs (it starts at #9), then moves the lit LED around the device. 

Exciting stuff, eh? 

Movement starts in one direction, and when you press the left button, the movement slows down. Every time you press the button, it slows down more until you've pressed it 5 times then it resets to the original speed.

When you press the right button, the moving LED changes direction and resets the speed to the starting speed.

You may have to hold a button down a little longer than expected to get the sketch to recognize the button push. If the sketch is busy calculating the position of the LED and so on, it may not register quick button pushes.

## Configuration

The sketch supports several configuration settings, implemented as `#defines` at the beginning of the sketch. You shouldn't need to modify any of them, but feel free to play around with them as you study the sketch.

```c
#define debug false
#define speedIncrement 100
#define speedLimit 500
#define speedStart 100
```

When you set `debug` to true, the sketch enables output to the Serial Monitor and updates the monitor as as the speed or direction changes. 

The speed of the LED movement is controlled by three settings:

* `speedStart` specifies the starting speed (in milliseconds). A value of 100 means the sketch waits 100ms every time it loops around reading the buttons and updating the position of the lit LED. Reduce this number to increase the initial speed of the moving LED.
* `speedIncrement` specifies the speed decrease (in milliseconds) every time you press the left button. When you press the button, the sketch increases the loop delay by the value here, thereby slowing down movement of the lit LED. 
* `speedLimit` specifies the maximum delay (in milliseconds) before the speed resets. As mentioned in the previous bullet, the sketch adds `speedIncrement` to the current delay value every time you press the right button - once the value exceeds 500 milliseconds, the speed resets to the value in `speedStart`. Increase this value to enable more button pushes before the speed resets.



