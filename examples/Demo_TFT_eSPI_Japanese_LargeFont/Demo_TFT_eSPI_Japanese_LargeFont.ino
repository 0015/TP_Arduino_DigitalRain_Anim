#include <TFT_eSPI.h>
#include <DigitalRainAnimation.hpp>
#include "MatrixCodeNFI34.h"

TFT_eSPI tft = TFT_eSPI();
DigitalRainAnimation<TFT_eSPI> matrix_effect = DigitalRainAnimation<TFT_eSPI>();

void setup() {
  Serial.begin(115200);
  Serial.println("\n\n TFT_eSPI with Japanese Large Font");

  tft.begin();
  tft.setRotation(0);
  tft.loadFont(MatrixCodeNFI34);

  matrix_effect.init(&tft, true, true);
}

void loop() {
  matrix_effect.loop();
}