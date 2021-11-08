//ESP32 ONLY
#include <TFT_eSPI.h>
#include <DigitalRainAnim.h>

TFT_eSPI tft = TFT_eSPI();
DigitalRainAnim digitalRainAnim = DigitalRainAnim(); 

void setup()
{
  Serial.begin(115200);
  Serial.println();
  xTaskCreate(task_display,"task_display", 2048, NULL, 1, NULL);
  xTaskCreate(task_input, "task_input", 1024, NULL, 1, NULL);
}

void task_display(void *pvParameter)
{
  tft.begin();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  digitalRainAnim.init(&tft);

  while(true)
  {
   digitalRainAnim.loop();
   vTaskDelay(1);
  }
}

void task_input(void *pvParameter)
{
  while(true){
    while(Serial.available() > 0){
      String str = Serial.readString();
      if(str.indexOf("key?") > -1){
        keyMode();
        }else{
        normalMode();
      }
    }
   vTaskDelay(10);
  }
}

void keyMode(){
  String newKey = digitalRainAnim.getKey(0).c_str();
  Serial.println(newKey);
}

void normalMode(){
  digitalRainAnim.resetKey();
}

void loop() {}
