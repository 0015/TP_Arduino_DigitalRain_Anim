#include <TFT_eSPI.h>
#include <DigitalRainAnim.h>

TFT_eSPI tft = TFT_eSPI();
DigitalRainAnim digitalRainAnim = DigitalRainAnim(); 

void setup()
{
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  digitalRainAnim.init(&tft);
}

void loop()
{
  digitalRainAnim.loop();

  while(Serial.available() > 0 ){
    String str = Serial.readString();
    if(str.indexOf("send") > -1){
       keyMode();
    }else{
       normalMode();
    }
  }
}

void keyMode(){
  String newKey = digitalRainAnim.getKey(0).c_str();
  Serial.println(newKey);
}

void normalMode(){
  digitalRainAnim.resetKey();
}
