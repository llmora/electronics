#include <Adafruit_NeoPixel.h> 
/*
 * Light up a strip of WS2812 LEDs when a switch is activated, slowly increasing
 * their brightness. When the switch is deactivated the light shuts down.
 * 
 * This was used as a "Pandora Box" prop for a drama class play: when the 
 * pandora box is open it lits up from the inside, when the box is closed the 
 * lights are shut down to save battery.
 * 
 * The LED strip "data in" (DI) pin should be tied to pin PB4 in the ATtiny85 
 * and the switch should be tied to pin PB0 (when the switch is open the LEDs 
 * switch on)
 * 
 * The code is based on attiny_pixel_touch by Dana Sniezko 
 * (https://github.com/danasf/attiny_pixel_switch/), released under GPLv3
 * 
*/

#define NUM_LEDS 3   // Adjust to the number of leds on your strip - too many 
                     // leds will require quite a bit of current, make sure your 
                     // power supply can handle it. We used 3 WS2811 LEDs and 
                     // powered from a 600mAh 1-cell 3.7V battery
#define DATA_PIN 4   // PB4 pin on the attiny85
#define SWITCH_PIN 0 // PB0 pin on the attiny85

// Global variables
uint8_t fadeShown = 0;
uint8_t switchedOff = 0;

// Initialise Strip - your LEDs may be different check the neopixel library
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, DATA_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    // Enable pull-up resistor on switch pin - when the switch is open the pin
    // goes to HIGH. when it is closed it goes to LOW
    pinMode(SWITCH_PIN, INPUT_PULLUP); 

    strip.begin();
    switchOff();
    strip.show(); // Initialize all pixels to 'off'
}

void loop() {

  // Check if the switch is enabled

  if(switchEnabled()) {
    if(fadeShown == 0) {
      fadeIn(0, 255, 2, 50);
    }
  } else {
    // If the switch is not enabled, switch off the LEDs (who can tell if the 
    // LEDs are off when you can't see them!!!)
    switchOff();
    fadeShown = 0;
  }

  delay(500); // Save battery in exchange of not-immediate response, a good 
              // trade-off as we are aiming for long battery life
}

boolean switchEnabled() {
  if(digitalRead(SWITCH_PIN) == HIGH) {
    return true;
  } else {
    return false;
  }
}

void colorFast(uint32_t c, uint8_t wait) {
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, c);
    }
    strip.show();
    delay(wait);
}

void switchOff() {
  colorFast(strip.Color(0,0,0),0);
}

void fadeIn(int start, int finish, int increment, int wait) {
  uint16_t i, j;

  for (j = start; j <= finish; j=j+increment) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, j, j, j);
    }

    if(switchEnabled() == false) {
      break;
    }
    strip.show();
    delay(wait);
  }

  if(switchEnabled() == false) {
    return;
  }

  colorFast(strip.Color(255,255,255),0);
  fadeShown = 1;
}
