#include <TFT_eSPI.h>
#include <SPI.h>
#include <DigitalRainAnim.h>
#include "Button2.h";

#define RIGHT_BUTTON_PIN  35
#define LEFT_BUTTON_PIN  0

TFT_eSPI tft = TFT_eSPI();
Button2 rButton = Button2(RIGHT_BUTTON_PIN);
Button2 lButton = Button2(LEFT_BUTTON_PIN);

DigitalRainAnim digitalRainAnim = DigitalRainAnim(); 

void setup()
{
  tft.begin();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  digitalRainAnim.init(&tft, 3, 20, 3, 20, 60);
  rButton.setClickHandler(rClick);
  lButton.setClickHandler(lClick);
}

void loop()
{
  digitalRainAnim.loop();
  rButton.loop();
  lButton.loop();
}

void rClick(Button2& btn) {
  digitalRainAnim.pause();
}

void lClick(Button2& btn) {
  digitalRainAnim.resume();
}
