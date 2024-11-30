#include "RGB.h"
#include "Arduino_motor.h"
RGB RGB_Data(2, 3, 7, 8, 6);
motor mtr(5, 9, 11);
void setup()
{
	Serial.begin(115200);
}

int local{};
int color[4]{};

void loop()
{
	if (local == 0)
	{
		mtr.stop();
		color[1] += RGB_Data.Getlevel(RED);
		delay(10);
		color[2] = RGB_Data.Getlevel(GREEN);
		delay(10); 
		color[3] = RGB_Data.Getlevel(BLUE)
		delay(480);

	}
	else
	{
		mtr.run(1);
		local--;
	}

}