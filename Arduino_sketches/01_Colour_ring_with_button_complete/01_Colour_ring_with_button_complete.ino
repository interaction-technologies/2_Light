// Include FastLED library by Daniel Garcia
#include <FastLED.h>

// Include Bounce2 library by Thomas O Fredericks
#include <Bounce2.h>

// Common naming from FastLED demos
#define DATA_PIN 9
#define NUM_LEDS 24

// Debouncer for button
Bounce button = Bounce();

// Array of led data
CRGB leds[NUM_LEDS];

void setup() { 
	// Neopixel ring is WS2812B chipset, GRB ordering
	FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
	FastLED.setBrightness(100);
	FastLED.clear();

	// Attach pin A0 to debouncer
	button.attach(A0,INPUT_PULLUP);
}

// Variable to save ring colour in
CRGB ring_colour;

void loop() { 
	button.update();

	// Set colour we want to use based on the button value
	if(button.read() == false){
		ring_colour = CRGB::Green;
	}else{
		ring_colour = CRGB::Blue;
	}

	// Update colours for ring
	for(int i=0; i<NUM_LEDS; i++){
		leds[i] = ring_colour; 
	}
	FastLED.show();  
}
