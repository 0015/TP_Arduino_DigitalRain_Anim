#include <TFT_eSPI.h>
#include <DigitalRainAnim.h>

TFT_eSPI tft = TFT_eSPI();
DigitalRainAnim digitalRainAnim = DigitalRainAnim(); 

void setup()
{
  tft.begin();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);

  digitalRainAnim.init(&tft, 10, 30, 5, 25, 60);
}

void loop()
{
  digitalRainAnim.loop();
}
