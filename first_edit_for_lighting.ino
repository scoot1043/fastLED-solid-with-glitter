#include <FastLED.h>

#define DATA_PIN    2
//#define CLK_PIN   4
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    60
CRGB leds[NUM_LEDS];

#define FRAMES_PER_SECOND   120
#define GLITTER_LENGTH      3
#define WHITE CRGB(100, 255, 255)
#define S4_NOGARO_BLUE CRGB(18, 62, 144)

void setup() {

  delay(3000); // 3 second delay for recovery

  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
}


void loop() {

  fill_solid(leds, NUM_LEDS, S4_NOGARO_BLUE);

  //Set brightness of individual LEDS to 50
  //As opposed to setting the 'master' brightness
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i].maximizeBrightness(50);
  }

  addGlitter(101);

  // send the 'leds' array out to the actual LED strip
  FastLED.show();
  // insert a delay to keep the framerate modest
  FastLED.delay(3000 / FRAMES_PER_SECOND);

}

void addGlitter( fract8 chanceOfGlitter)
{
  if ( random8() < chanceOfGlitter) {
    uint16_t var = random16(NUM_LEDS);

    for (int i = 0; i < GLITTER_LENGTH; i++)
    {
      leds[var + i] = WHITE;
      leds[var + i].maximizeBrightness(255);
    }
  }

}
