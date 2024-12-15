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
	local_C[0] = malloc(4 * sizeof(int));
	local_C[1] = malloc(4 * sizeof(int));
	local_C[2] = malloc(4 * sizeof(int));
	local_C[3] = malloc(4 * sizeof(int));
	while (!digitalRead(4))
	{
		RGB_Data.SetColor(local_C[1]);
		while (digitalRead(4))
	}
	while (!digitalRead(4))
	{
		RGB_Data.SetColor(local_C[2]);
		while (digitalRead(4))
	}
	while (!digitalRead(4))
	{
		RGB_Data.SetColor(local_C[3]);
		while (digitalRead(4))
	}
}

int local{};
int color[4]{};
bool rtm = false;

void loop()
{
	if (!digitalRead(12))
	{
		if (local == 0 && !rtm)
		{
			mtr.stop();
			color[1] += RGB_Data.Getlevel(RED);
			delay(10);
			color[2] = RGB_Data.Getlevel(GREEN);
			delay(10);
			color[3] = RGB_Data.Getlevel(BLUE);
			delay(480);
			if ((color[1] > (local_C[1][1] * 0.9)) || (color[1] < (local_C[1][1] * 1.1)))
			{
				if ((color[2] > (local_C[1][2] * 0.9)) || (color[2] < (local_C[1][2] * 1.1)))
				{
					if ((color[3] > (local_C[1][3] * 0.9)) || (color[2] < (local_C[1][3] * 1.1)))
					{
						local = 0;
					}
				}
			}
			else if ((color[1] > (local_C[2][1] * 0.9)) || (color[1] < (local_C[2][1] * 1.1)))
			{
				if ((color[2] > (local_C[2][2] * 0.9)) || (color[2] < (local_C[2][2] * 1.1)))
				{
					if ((color[3] > (local_C[2][3] * 0.9)) || (color[2] < (local_C[2][3] * 1.1)))
					{
						local = 400;
					}
				}
			}
			else if ((color[1] > (local_C[3][1] * 0.9)) || (color[1] < (local_C[3][1] * 1.1)))
			{
				if ((color[2] > (local_C[3][2] * 0.9)) || (color[2] < (local_C[3][2] * 1.1)))
				{
					if ((color[3] > (local_C[3][3] * 0.9)) || (color[2] < (local_C[3][3] * 1.1)))
					{
						local = 800;
					}
				}
			}
			else
			{
				local = 0;
			}
			mtr.setstep(local);
			rtm = !rtm;
		}
		else if (!rtm)
		{
			mtr.back();
			rtm = !rtm;
		}
		else
		{
			mtr.run(1);
			local--;
		}
	}
	else
	{
		mtr.stop();
		local = 0;
	}
}