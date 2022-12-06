#include <TFT_eSPI.h>
#include <DigitalRainAnimation.hpp>

TFT_eSPI tft = TFT_eSPI();
DigitalRainAnimation<TFT_eSPI> matrix_effect = DigitalRainAnimation<TFT_eSPI>();

void setup() {
  Serial.begin(115200);
  Serial.println("\n\n TFT_eSPI ShowCase");

  tft.begin();
  tft.setRotation(1);

  matrix_effect.init(&tft);
  matrix_effect.setTextAnimMode(AnimMode::SHOWCASE, "\nWake Up, Neo...    \nThe Matrix has you.    \nFollow     \nthe white rabbit.     \nKnock, knock, Neo.                 ");
}

void loop() {
  matrix_effect.loop();
}