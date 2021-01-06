#include <TFT_eSPI.h>
#include <SPI.h>
#include <DigitalRainAnim.h>
TFT_eSPI tft = TFT_eSPI();

DigitalRainAnim digitalRainAnim = DigitalRainAnim(); 

void setup()
{
  tft.begin();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  digitalRainAnim.init(&tft);
}

void loop()
{
  digitalRainAnim.loop();
}
