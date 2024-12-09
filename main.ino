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

enum lolc{
	red = 0,
	green = 200,
	blue = 400
}

void loop()
{
	if (local == 0)
	{
		mtr.stop();
		color[1] += RGB_Data.Getlevel(RED);
		delay(10);
		color[2] = RGB_Data.Getlevel(GREEN);
		delay(10); 
		color[3] = RGB_Data.Getlevel(BLUE);
		delay(480);
		if (color[1] > color[2] && color[1] > color[3])
			local = lolc.red;
		else if (color[2] > 3)
			local = lolc.green;
		else
			local = lolc.blue;
	}
	else
	{
		mtr.run(1);
		local--;
	}

}