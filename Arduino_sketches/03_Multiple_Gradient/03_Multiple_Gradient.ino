// Include FastLED library by Daniel Garcia
#include <FastLED.h>

// Common naming from FastLED demos
#define DATA_PIN 9
#define NUM_LEDS 5

// Array of led data
CRGB leds[NUM_LEDS];

// Create a gradient palette of the Irish flag
// |-----------------------|
// GREEN.....WHITE....ORANGE
DEFINE_GRADIENT_PALETTE(irish_flag_p){
   0,    0,   255, 0,
   65,   0,   255, 0,
   100,  255, 255, 255, 
   180,  255, 100, 0,
   255,  255, 100, 0
};
CRGBPalette256 irish_flag = irish_flag_p; 

void setup() { 
   // 8mm Neopixel pins are WS2812B chipset, RGB ordering
   FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
   FastLED.clear();

   // Draw gradient across strip using map()
   for(uint8_t i=0; i<NUM_LEDS; i++){
      leds[i] = ColorFromPalette(irish_flag, map(i,0,NUM_LEDS-1,0,255));
   }
   FastLED.show();
}


void loop() { 
}
