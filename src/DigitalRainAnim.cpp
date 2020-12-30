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
}

//updating each line with a new length, Y position, and speed.
void DigitalRainAnim::lineUpdate(int lineNum){
    line_length[lineNum] = this->getRandomNum(line_len_min, line_len_max);
    line_pos[lineNum] = this->setYPos(line_length[lineNum]);
    line_speed[lineNum] = this->getRandomNum(line_speed_min, line_speed_max);
}

//while moving vertically, the color value changes and the character changes as well.
void DigitalRainAnim::lineAnimation(int lineNum)
{
  int startX = lineNum * LINE_WIDTH;
  tft_DigitalRainAnim->fillRect(startX, 0, 10, 240,TFT_BLACK);

  int currentY = 0;
  for(int i=0; i<line_length[lineNum]; i++){
    int greenVal = map(i, 0, line_length[lineNum], 25, 255);
    tft_DigitalRainAnim->setTextColor(tft_DigitalRainAnim->color565(0, greenVal, 0), TFT_BLACK);      
    tft_DigitalRainAnim->drawString(this->getASCIIChar(), startX, line_pos[lineNum] + currentY, FONT_SIZE);  
    currentY = (i * LETTER_HEIGHT);
  }  

  tft_DigitalRainAnim->setTextColor(TFT_WHITE, TFT_BLACK);
  tft_DigitalRainAnim->drawString(this->getASCIIChar(), startX, line_pos[lineNum] +currentY, FONT_SIZE);
  line_pos[lineNum] += line_speed[lineNum];

  if (line_pos[lineNum] >= height){
    this->lineUpdate(lineNum);
  }
}

//a function where animation continues to run.
void DigitalRainAnim::play(){
  uint32_t currentTime = millis();
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

//move the position to start from out of the screen.
int DigitalRainAnim::setYPos(int lineLen){
  return lineLen * -20;
}

//the function is to get the random number (including max)
int DigitalRainAnim::getRandomNum(int min, int max){
  return random(min, max+1);
}