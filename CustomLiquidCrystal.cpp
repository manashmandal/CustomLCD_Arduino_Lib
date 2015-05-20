#include "CustomCrystalDisplay.h"


void CustomLCD::setLCD(uint8_t col, uint8_t row)
{
	lcdRows = row;
	lcdCols = col;
}

uint8_t CustomLCD::getCol()
{
	return lcdCols;
}

uint8_t CustomLCD::getRow()
{
	return lcdRows;
}

uint8_t CustomLCD::get_distance()
{
	return getCol() + 1 - CustomLCD::x;
}

void CustomLCD::transfer(char *string)
{
	int xPos = x;
	while (x < getCol())
	{
		clear();
		for  (int index = 0, xPos = x; xPos < getCol(); xPos++, index++){
			setCursor(xPos, y);
			print(string[index]);
		}
		delay(scroll_delay);
		clear();
		x++;
	}
}

void CustomLCD::word_scroll(char *str, uint8_t del)
{
	//String Length
	wordlength = strlen(str);
	scroll_delay = del;

	//Getting row and column for boundary calculation
	uint8_t max_col = getCol();
	uint8_t max_row = getRow();

	//Initial Positions
	 CustomLCD::x = 0;
	 CustomLCD::y = 0;

	//The block that actually do the scrolling
	while (true){
		if (get_distance() >= wordlength){
			//print("Func called");
			setCursor(x, y);
			print(str);
			delay(del);
			clear();
			x++;

			if (get_distance() == wordlength){
				transfer(str);
				y++;
				x = 0;
			}
		}
		//If row goes unbounded this codeblock resets the coordinates
		if (y >= max_row) {
			y = 0;
			x = 0;
		}
	}
}