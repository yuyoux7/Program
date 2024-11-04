#include "RGB.h"
RGB RGB_Data(2, 3, 7, 8, 6);
void setup()
{
	Serial.begin(115200);
}

void loop()
{
	Serial.print(RGB_Data.Getlevel(RED));
	Serial.print(" ");
	delay(10);
	Serial.print(RGB_Data.Getlevel(GREEN));
	Serial.print(" ");
	delay(10);
	Serial.println(RGB_Data.Getlevel(BLUE));
	delay(480);
}