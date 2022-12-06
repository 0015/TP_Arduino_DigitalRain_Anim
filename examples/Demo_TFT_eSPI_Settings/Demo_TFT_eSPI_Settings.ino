#include <TFT_eSPI.h>
#include <DigitalRainAnimation.hpp>

TFT_eSPI tft = TFT_eSPI();
DigitalRainAnimation<TFT_eSPI> matrix_effect = DigitalRainAnimation<TFT_eSPI>();

void setup() {
  Serial.begin(115200);
  Serial.println("\n\n TFT_eSPI Settings");

  tft.begin();
  tft.setRotation(0);

  matrix_effect.init(&tft);
  matrix_effect.setup(
  10 /* Line Min */, 
  30,  /* Line Max */
  5,  /* Speed Min */
  25,  /* Speed Max */
  60  /* Screen Update Interval */);
}

void loop() {
  matrix_effect.loop();
}