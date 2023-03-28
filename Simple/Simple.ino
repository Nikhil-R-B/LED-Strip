#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    60
//#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
//#define POT_PIN     A1

CRGB leds[NUM_LEDS];
CRGB background[NUM_LEDS];

uint8_t hue = 0;
uint8_t patternCounter = 0;
uint16_t x;
int scale;
uint16_t t;

void setup() {
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
//  FastLED.setBrightness(  BRIGHTNESS );
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
//  FastLED.setCorrection(); //   Three main types: UncorrectedColor, TypicalLEDStrip, TypicalPixelString
//  FastLED.setTemperature(); //  To set the temperature of the colour
}

void loop() {
//  leds[0] = CRGB::Red;
//  leds[1] = CRGB::Green;
//  leds[2] = CRGB::Blue;
//  FastLED.show();
//  for(int i = 0; i < NUM_LEDS; i++){
//    leds[i] = CRGB(0, 255 - 3*i, 3*i);
//    FastLED.setBrightness(i);
//    FastLED.show();
//    delay(30);
//  }
//  for(int i = NUM_LEDS; i > 0; i--){
//    leds[i] = CRGB(3*i, 0, 255 - 3*i);
//    FastLED.setBrightness(60 - i);
//    FastLED.show();
//    delay(30);
//  }
//  uint16_t potRead = analogRead(POT_PIN);
//  uint8_t brightness = map(potRead, 0, 1023, 0, 200);
//  FastLED.setBrightness(brightness);
//  for(int i = 0; i < NUM_LEDS; i++){
//    leds[i] = CHSV(hue + i*10, 255, 255);
//  }
//  EVERY_N_MILLISECONDS(15){
//    hue++;
//  }
//  FastLED.show();
//  switch(patternCounter){
//    case 0;
//    movingDots();
//    breakl;
//    case 1;
//    rainbowBeat();
//    break;
//    case 2;
//    redWhiteBlue;
//    break;
//  }
//  EVERY_N_SECONDS(5){
//    nextPattern();
//  }
//  FastLED.show();
//  x = 0;
//  t = millis() / 5;
//  scale = beatsin8(10, 10, 30);
//  for(int i = 0; i < NUM_LEDS; i++){
//    uint8_t noise = inoise8(i * scale + 8, t);
//    uint8_t hue = map(noise, 50, 180, 0, 255);
//    leds[i] = CHSV(hue, 255, 255);
//  }
//  FastLED.show();
  drawBackground();
  drawMovingPixel();
  EVERY_N_MILLISECONDS(20){
    fadeToBlackBy(leds, NUM_LEDS, 10);
    nblend(leds, background, NUM_LEDS, 30);
  }
  FastLED.show();
}

void drawBackground(){
  fill_noise16(background, NUM_LEDS, 1, millis(), 30, 1, 0, 50, millis() / 3, 10);
}

void drawMovingPixel(){
  uint16_t pos = inoise16(millis() * 100);
  pos = constrain(pos, 13000, 51000);
  pos = map(pos, 13000, 51000, 0, NUM_LEDS - 1);
  leds[pos] = CRGB::Red;
}

//void nextPattern(){
//  patternCounter = (patternCounter + 1) % 3;
//}
//
//void movingDots(){
//  uint8_t posBeat1 = beatsin8(30, 0, NUM_LEDS - 1, 0, 0); //  beat8 produces a saw tooth wave
//  uint8_t posBeat2 = beatsin8(60, 0, NUM_LEDS - 1, 0, 0);
//  uint8_t posBeat3 = beatsin8(30, 0, NUM_LEDS - 1, 0, 127);
//  uint8_t posBeat4 = beatsin8(60, 0, NUM_LEDS - 1, 0, 127);
//  uint8_t coolBeat = beatsin8(45, 0, 255, 0, 0);
//  leds[(posBeat1 + posBeat2)/2] = CHSV(coolBeat, 255, 255);
//  leds[(posBeat3 + posBeat4)/2] = CHSV(coolBeat, 255, 255);
//  EVERY_N_MILLISECONDS(1){
//    for(int i = 0; i < 4; i++){
//      blur1d(leds, NUM_LEDS, 50);
//    }
//  }
//  fadeToBlackBy(leds, NUM_LEDS, 10);
//}
