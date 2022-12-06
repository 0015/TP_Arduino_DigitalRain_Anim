#define LGFX_AUTODETECT
#define LGFX_USE_V1
#include <LovyanGFX.hpp>
#include <LGFX_AUTODETECT.hpp>  
#include <DigitalRainAnimation.hpp>

static LGFX tft;
DigitalRainAnimation<LGFX> matrix_effect = DigitalRainAnimation<LGFX>();

void setup() {
  Serial.begin(115200);
  Serial.println("\n\n LovyanGFX Basic");

  tft.begin();
  tft.setRotation(0);
  tft.setBrightness(255);
  matrix_effect.init(&tft);
}

void loop() {
  matrix_effect.loop();
}