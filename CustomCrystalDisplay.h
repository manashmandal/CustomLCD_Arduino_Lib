#ifndef CustomCrystalDisplay_h
#define CustomCrystalDisplay_h

#include <Arduino.h>
#include "LiquidCrystal.h"

class CustomLCD : public LiquidCrystal
{

private:
	
	//Initial Positions
	uint8_t x = 0 , y = 0;
	uint8_t scroll_delay;

	//Storage for row and column
	 uint8_t lcdRows;
	 uint8_t lcdCols;
	 int wordlength;
	 //Distance from first character to the last boundary of lcd
	 uint8_t distance;

public:
	//Function for scrolling from left to right 
	void word_scroll(char *str, uint8_t del);

	//Set LCD Dimension
	void setLCD(uint8_t col, uint8_t row);

	//Get LCD Dimension
	uint8_t getRow();
	uint8_t getCol();

	//Using Constructor from LiquidCrystal
	CustomLCD(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f) 
		
		: LiquidCrystal(a, b, c, d, e, f) {}

	//Calculate distance from first character of the string to the last LCD boundary
	uint8_t get_distance();

	//bool transfer(char * string);
	void transfer(char *string);

};

#endif