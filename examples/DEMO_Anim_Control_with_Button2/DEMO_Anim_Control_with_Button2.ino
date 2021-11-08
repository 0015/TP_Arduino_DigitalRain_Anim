//Button2 Library
//https://github.com/LennartHennigs/Button2

#include <TFT_eSPI.h>
#include <DigitalRainAnim.h>
#include "Button2.h"

#define RIGHT_BUTTON_PIN  35
#define LEFT_BUTTON_PIN  0

TFT_eSPI tft = TFT_eSPI();
DigitalRainAnim digitalRainAnim = DigitalRainAnim(); 

Button2 rButton, lButton;

void setup()
{
  tft.begin();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  digitalRainAnim.init(&tft, 3, 20, 3, 20, 60);
  
  rButton.begin(RIGHT_BUTTON_PIN);
  rButton.setClickHandler(click);

  lButton.begin(LEFT_BUTTON_PIN);
  lButton.setClickHandler(click);
}

void loop()
{
  digitalRainAnim.loop();
  rButton.loop();
  lButton.loop();
}

void click(Button2& btn) {
    if (btn == rButton) {
      digitalRainAnim.pause();
    } else if (btn == lButton) {
      digitalRainAnim.resume();
    }
}