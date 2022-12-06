#include <TFT_eSPI.h>
#include <DigitalRainAnimation.hpp>

TFT_eSPI tft = TFT_eSPI();
DigitalRainAnimation<TFT_eSPI> matrix_effect = DigitalRainAnimation<TFT_eSPI>();

void setup() {
  Serial.begin(115200);
  Serial.println("\n\n TFT_eSPI Color Settings");

  tft.begin();
  tft.setRotation(0);

  matrix_effect.init(&tft);
  matrix_effect.setTextColor(0, 0, 255);
  matrix_effect.setHeadCharColor(0, 255, 255);
}

void loop() {
  matrix_effect.loop();
}