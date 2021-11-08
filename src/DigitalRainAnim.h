/*
  DigitalRainAnim.h - Library for Digital Rain Animation for TFT_eSPI Using ESP32, ESP8266.
  Created by Eric Nam, November 08, 2021.
  Released into the public domain.
*/

#ifndef DigitalRainAnim_h
#define DigitalRainAnim_h

#include <TFT_eSPI.h>
#include <SPI.h>
#include <vector>
#include <string>

#define FONT_SIZE 2              //set font size 2
#define LINE_WIDTH 10            //width for font size 2
#define LETTER_HEIGHT 14         //height for font size 2
#define KEY_RESET_TIME 60 * 1000 //1 Min reset time

class DigitalRainAnim
{
  public:
    DigitalRainAnim();   
    void init(TFT_eSPI* tft, bool biggerText = false, bool alphabetOnly = false);            //initialization
    void init(TFT_eSPI* tft, int new_line_len_min, int new_line_len_max, int new_line_speed_min, int new_line_speed_max, int new_timeFrame, bool biggerText = false, bool alphabetOnly = false); //initialization with parameters
    void loop();                         //loop animation
    void pause();                        //pause animation 
    void resume();                       //resume animation
    std::string getKey(int key_length);  //generating new key
    void resetKey(); 
    void setHeadCharColor(uint8_t red, uint8_t green, uint8_t blue); //set Head Char Color
    void setTextColor(uint8_t red, uint8_t green, uint8_t blue); //set Text Color
    void setBGColor(uint8_t red, uint8_t green, uint8_t blue); //set BG Color
    void setBigText(bool isOn);          //set Bigger Test
    
  private:
    TFT_eSPI* tft_DigitalRainAnim; //target display TFT_eSPI
    int line_len_min;              //minimum length of characters 
    int line_len_max;              //maximum length of characters 
    int line_speed_min;            //minimum vertical move speed
    int line_speed_max;            //maximum vertical move speed
    int width, height;             //width, height of display
    int numOfline;                 //number of calculated row
    int timeFrame;                 //time frame for drawing
    uint8_t fontSize;              //default font size 2
    uint8_t lineWidth;             //default line width
    uint8_t letterHeight;          //default letter height
    bool isPlaying;                //boolean for play or pause
    bool isAlphabetOnly;           //boolean for showing Alphabet only
    uint32_t lastDrawTime;         //checking last drawing time
    uint32_t lastUpdatedKeyTime;   //checking last generating key time
    uint16_t headCharColor;        //having a text color  
    uint16_t textColor;            //having a text color  
    uint16_t bgColor;              //having a bg color  
    std::vector<int> line_length;  //dynamic array for each line of vertical length
    std::vector<int> line_pos;     //dynamic array for eacg line Y position
    std::vector<int> line_speed;   //dynamic array for eacg line speed
    std::string keyString;         //storing generated key

    void prepareAnim();                 //the function is to prepare all lines at the beginning
    void lineUpdate(int lineNum);       //the function is to update each line after disappeared from the screen
    void lineAnimation(int lineNum);    //the function is to update each line
    String getASCIIChar();              //the function is to get the random ASCII char 
    String getAbcASCIIChar();           //the function is to get only alphabet lowercase and uppercase
    int setYPos(int lineLen);           //the function is to update the position of line
    int getRandomNum(int min, int max); //the function is to get the random number (including max)
    uint16_t luminance(uint16_t color, uint8_t luminance); //the function is to get a color with luminance
};

#endif