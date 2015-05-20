
#include "CustomCrystalDisplay.h"

CustomLCD lcd(12, 11, 5, 4, 3, 2);


void setup()
{
	lcd.begin(16, 4);
	lcd.setLCD(16, 4);
	lcd.word_scroll("E_Scholars", 1000);
}



void loop()
{

}

