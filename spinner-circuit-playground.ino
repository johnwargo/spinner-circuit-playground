/* ********************************************************
 * Circuit Playground Spinner
 * By John M. Wargo (https://johnwargo.com)
 * 
 * This simple sketch spins one NeoPixel LED around the
 * Circuit Playground device. Use the left button to 
 * decrease speed. Use the right button to change the 
 * direction of the lit LED.
*/
// https://github.com/adafruit/Adafruit_CircuitPlayground
#include <Adafruit_CircuitPlayground.h>

#define debug false
#define speedIncrement 100
#define speedLimit 500
#define speedStart 100

// variables to track left button state
bool leftButtonIsDown = false;
bool leftButtonWasDown = false;
// variables to track right button state
bool rightButtonIsDown = false;
bool rightButtonWasDown = false;

// Some other variables
bool direction = true;  // which direction are the lights moving?
int speed = speedStart; // how fast is it moving?
int currentLED = -1;    // which LED is currently illuminated?

void setup() {
  if (debug) {
    Serial.begin(9600);
    delay(500);
    Serial.println("Circuit Playground Spinner");
  }

  // Initialize the Circuit Playground board
  CircuitPlayground.begin();
  // Turn all of the LEDs green to let everyone know we're ready to go
  setAllPixels(0, 255, 0);
  // wait a second (literally)
  delay(1000);
  // clear all of the LEDs (turn them off)
  CircuitPlayground.clearPixels();
}

void loop() {
  // Update the current LED Position
  updateNeoPixels();
  // Then get the state of the button and switches
  leftButtonIsDown = CircuitPlayground.leftButton();
  rightButtonIsDown = CircuitPlayground.rightButton();
  // Is the left button pressed?
  if (leftButtonWasDown == false && leftButtonIsDown == true) {
    if (debug) {
      Serial.println("Left button pressed");
    }
    speed += speedIncrement;                  // increase delay, which means decrease speed
    if (speed > speedLimit) speed = speedStart;  // Reset once we've gone too far
    if (debug) {
      Serial.println("Speed: " + String(speed));
    }
  }
  // Is the right button pressed?
  if (rightButtonWasDown == false && rightButtonIsDown == true) {
    if (debug) {
      Serial.println("Right button pressed");
    }
    direction = !direction;  // Change direction
    speed = speedStart;  // Reset the speed
  }

  // Save the button state as previous button state
  leftButtonWasDown = leftButtonIsDown;
  rightButtonWasDown = rightButtonIsDown;
  // and wait a bit before checking again
  delay(speed);
}

void updateNeoPixels() {
  // Handles moving the illiminated LED around the ring
  // Turn off the current LED
  CircuitPlayground.setPixelColor(currentLED, 0, 0, 0);
  // Increment the current LED position based on direction +/-
  currentLED += direction ? 1 : -1;
  // Did we go past start? Then move to the end
  if (currentLED < 0) currentLED = 9;
  // Did we go past the end? Then move to the beginning
  if (currentLED > 9) currentLED = 0;  
  // Then illuminate the selected NeoPixel in blue.
  CircuitPlayground.setPixelColor(currentLED, 0, 0, 255);
}

void setAllPixels(int red, int green, int blue) {
  // Reset all NeoPixels to the specified color
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, red, green, blue);
  }
}
