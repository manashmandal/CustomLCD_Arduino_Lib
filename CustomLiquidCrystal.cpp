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



void CustomLCD::word_scroll(char *str, uint8_t del)
{
	//String Length
	wordlength = strlen(str);

	//Getting row and column for boundary calculation
	uint8_t max_col = getCol();
	uint8_t max_row = getRow();

	//Initial Positions
	uint8_t x = 0;
	uint8_t y = 0;

	int iterator = 0;

	//The block that actually do the scrolling
	while (true){

		iterator = x + wordlength;

		if (iterator <= max_col){
			setCursor(x, y);
			LiquidCrystal::print(str);
			delay(del);
			LiquidCrystal::clear();

			if (iterator == max_col){
				y++;
				x = -1;  
				

			}

			x++;
		}

		if (y >= max_row) {
			y = 0;
			x = 0;
		}
		
	}
	
	

}