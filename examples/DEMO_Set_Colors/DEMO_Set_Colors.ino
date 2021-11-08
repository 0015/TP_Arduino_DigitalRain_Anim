#include <TFT_eSPI.h>
#include <DigitalRainAnim.h>

TFT_eSPI tft = TFT_eSPI();
DigitalRainAnim digitalRainAnim = DigitalRainAnim(); 

void setup()
{
  tft.begin();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);

  digitalRainAnim.init(&tft);
  digitalRainAnim.setTextColor(0, 0, 255);
  digitalRainAnim.setBGColor(255, 255, 255);
  digitalRainAnim.setHeadCharColor(255, 0, 0);
}

void loop()
{
  digitalRainAnim.loop();
}
