#include "RGB.h"
RGB RGB_Data(2, 3, 7, 8, 6);
void setup()
{

}

void loop()
{
	RGB_Data.Getlevel(RED);
	RGB_Data.Getlevel(GREEN);
	RGB_Data.Getlevel(BLUE);
}