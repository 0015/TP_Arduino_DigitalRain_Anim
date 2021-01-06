/*
  DigitalRainAnim.cpp - Library for Digital Rain Animation for TFT_eSPI.
  Created by Eric Nam, December 30, 2020.
  Released into the public domain.
*/

#include "DigitalRainAnim.h"

DigitalRainAnim::DigitalRainAnim(){}

//initialze with only tft
void DigitalRainAnim::init(TFT_eSPI* tft){
  
  tft_DigitalRainAnim = tft; 
  line_len_min = 3;
  line_len_max = 20;
  line_speed_min = 3;
  line_speed_max = 15;
  timeFrame = 100;
 
  this->prepareAnim();
}

//initialze with only tft and params
void DigitalRainAnim::init(TFT_eSPI* tft, int new_line_len_min, int new_line_len_max, int new_line_speed_min, int new_line_speed_max, int new_timeFrame)
{
  tft_DigitalRainAnim = tft; 
  line_len_min = new_line_len_min;
  line_len_max = new_line_len_max;
  line_speed_min = new_line_speed_min;
  line_speed_max = new_line_speed_max;
  timeFrame = new_timeFrame;
  
  this->prepareAnim();
}

//checking how many lines it can draw from the width of the screen.
//the size of the array is determined by the number of lines.
void DigitalRainAnim::prepareAnim()
{
  lastDrawTime = millis() - timeFrame;
  width = tft_DigitalRainAnim->width();
  height = tft_DigitalRainAnim->height();

  numOfline = width / LINE_WIDTH;
  
  for(int i = 0; i < numOfline; i++){
    line_length.push_back(this->getRandomNum(line_len_min, line_len_max));
    line_pos.push_back(this->setYPos(line_length[i]));
    line_speed.push_back(this->getRandomNum(line_speed_min, line_speed_max));
  }

  isPlaying = true;
  lastUpdatedKeyTime = millis() - timeFrame;
}

//updating each line with a new length, Y position, and speed.
void DigitalRainAnim::lineUpdate(int lineNum){
    line_length[lineNum] = this->getRandomNum(line_len_min, line_len_max);
    line_pos[lineNum] = this->setYPos(line_length[lineNum]);
    line_speed[lineNum] = this->getRandomNum(line_speed_min, line_speed_max);
}

//while moving vertically, the color value changes and the character changes as well.
//if a random key is generated, switch to red.
void DigitalRainAnim::lineAnimation(int lineNum)
{
  int startX = lineNum * LINE_WIDTH;
  int currentY = 0;
  tft_DigitalRainAnim->fillRect(startX, 0, 10, height, TFT_BLACK);

  bool isKeyMode = keyString.length() > 0; 

  for(int i=0; i<line_length[lineNum]; i++){
    int colorVal = map(i, 0, line_length[lineNum], 25, 255);
    tft_DigitalRainAnim->setTextColor(isKeyMode ? tft_DigitalRainAnim->color565(colorVal, 0, 0) : tft_DigitalRainAnim->color565(0, colorVal, 0), TFT_BLACK);      
    tft_DigitalRainAnim->drawString(this->getASCIIChar(), startX, line_pos[lineNum] + currentY, FONT_SIZE);  
    currentY = (i * LETTER_HEIGHT);
  }  

  tft_DigitalRainAnim->setTextColor(TFT_WHITE, TFT_BLACK);
  if(keyString.length() > lineNum){
    char _char = keyString.at(lineNum);
    const char *keyChar = &_char;
    tft_DigitalRainAnim->drawString(keyChar, startX, line_pos[lineNum] + currentY, FONT_SIZE);    
  }else{
    tft_DigitalRainAnim->drawString(this->getASCIIChar(), startX, line_pos[lineNum] + currentY, FONT_SIZE);  
  }

  line_pos[lineNum] += line_speed[lineNum];

  if (line_pos[lineNum] >= height){
    this->lineUpdate(lineNum);
  }
}

//a function where animation continues to run.
void DigitalRainAnim::loop(){
  uint32_t currentTime = millis();
   if (((currentTime - lastUpdatedKeyTime) > KEY_RESET_TIME)) {
      this->resetKey();
    }

  if (((currentTime - lastDrawTime) < timeFrame)) {
    return;
  }

  if(isPlaying) for(int i = 0; i < numOfline; i++) this->lineAnimation(i);
  lastDrawTime = currentTime;
}

//a function to stop animation.
void DigitalRainAnim::pause(){
  isPlaying = false;
}

//a function to resume animation.
void DigitalRainAnim::resume(){
  isPlaying = true;
}

//a function that gets randomly from ASCII code 33 to 126.
String DigitalRainAnim::getASCIIChar()
{
  return String((char)(random(33, 127)));
}

//a function that gets only alphabets from ASCII code.
String DigitalRainAnim::getAbcASCIIChar()
{
  return String((char)(random(0,2) == 0 ?random(65, 91) : random(97, 123)));
}

//move the position to start from out of the screen.
int DigitalRainAnim::setYPos(int lineLen){
  return lineLen * -20;
}

//the function is to get the random number (including max)
int DigitalRainAnim::getRandomNum(int min, int max){
  return random(min, max+1);
}

//the function is to generate a random key with length with a length
std::string DigitalRainAnim::getKey(int key_length){
  this->resetKey();
  int maxKeyLength =(key_length > 0 ? (key_length > numOfline ? numOfline : key_length) : numOfline);

  for(int i = 0; i < maxKeyLength; i++){
    keyString.append((this->getAbcASCIIChar()).c_str());
  }

  return keyString;
}

//the function is to remove the generated key
void DigitalRainAnim::resetKey(){
  keyString = "";
  lastUpdatedKeyTime = millis();
}
