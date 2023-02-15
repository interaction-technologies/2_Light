// Include FastLED library by Daniel Garcia
#include <FastLED.h>

// Common naming from FastLED demos
#define DATA_PIN 9
#define NUM_LEDS 24

// Array of led data
CRGB leds[NUM_LEDS];

void setup() { 
	// Neopixel ring is WS2812B chipset, GRB ordering
	FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
	FastLED.setBrightness(100);
	FastLED.clear();
}

void loop() { 
	// Set each LED to Red
	for(int i=0; i<NUM_LEDS; i++){
		leds[i] = CRGB::Red;
	}
	FastLED.show();
}
