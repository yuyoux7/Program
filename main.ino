#include "RGB.h"
#include "Arduino_motor.h"
int* local_C[4]{};
RGB RGB_Data(2, 3, 7, 8, 6);
motor mtr(5, 9, 11);
void setup()
{
	//Serial.begin(115200);
	pinMode(4, 0);
	pinMode(12, 0);
	local_C[0] = (int*)malloc(4 * sizeof(int));
	local_C[1] = (int*)malloc(4 * sizeof(int));
	local_C[2] = (int*)malloc(4 * sizeof(int));
	local_C[3] = (int*)malloc(4 * sizeof(int));
	while (!digitalRead(4))
	{
		RGB_Data.SetColor(local_C[1]);
	}
	while (digitalRead(4))
	while (!digitalRead(4))
	{
		RGB_Data.SetColor(local_C[2]);
	}
	while (digitalRead(4))
	while (!digitalRead(4))
	{
		RGB_Data.SetColor(local_C[3]);
	}
	while (digitalRead(4))
}

int local{};
int color[4]{};

void loop()
{
	if (!digitalRead(12))
	{
		if (local == 0)
		{
			mtr.stop();
			color[1] = RGB_Data.Getlevel(RED);
			delay(150);
			color[2] = RGB_Data.Getlevel(GREEN);
			delay(150);
			color[3] = RGB_Data.Getlevel(BLUE);
			delay(200);
			RGB_Data.Process(&local, local_C, color);
			mtr.setstep(local);
		}
		else
		{
			mtr.run(1);
			//local--;
			delay(300);
			mtr.back();
			delay(300);
			local = 0;
		}
	}
	else
	{
		mtr.stop();
		local = 0;
	}
}