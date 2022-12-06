#include <Arduino_GFX_Library.h>
#include <DigitalRainAnimation.hpp>

#define TFT_BL 45
Arduino_ESP32RGBPanel *bus = new Arduino_ESP32RGBPanel(
  GFX_NOT_DEFINED /* CS */, GFX_NOT_DEFINED /* SCK */, GFX_NOT_DEFINED /* SDA */,
  40 /* DE */, 48 /* VSYNC */, 47 /* HSYNC */, 14 /* PCLK */,
  4 /* R0 */, 5 /* R1 */, 6 /* R2 */, 7 /* R3 */, 15 /* R4 */,
  16 /* G0 */, 17 /* G1 */, 18 /* G2 */, 8 /* G3 */, 3 /* G4 */, 46 /* G5 */,
  9 /* B0 */, 10 /* B1 */, 11 /* B2 */, 12 /* B3 */, 13 /* B4 */
);
Arduino_RPi_DPI_RGBPanel *gfx = new Arduino_RPi_DPI_RGBPanel(
  bus,
  480 /* width */, 0 /* hsync_polarity */, 8 /* hsync_front_porch */, 4 /* hsync_pulse_width */, 43 /* hsync_back_porch */,
  272 /* height */, 0 /* vsync_polarity */, 8 /* vsync_front_porch */, 4 /* vsync_pulse_width */, 12 /* vsync_back_porch */,
  1 /* pclk_active_neg */, 9000000 /* prefer_speed */, true /* auto_flush */);

DigitalRainAnimation<Arduino_GFX> matrix_effect = DigitalRainAnimation<Arduino_GFX>();

void setup() {
  Serial.begin(115200);
  Serial.println("\n\n Arduino_GFX Test!");

#ifdef TFT_BL
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);
#endif

  gfx->begin();
  matrix_effect.init(gfx);
}

void loop() {
  matrix_effect.loop();
}