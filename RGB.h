#pragma once

#define BLUE 0xFF0000
#define GREEN 0x00FF00
#define RED 0x0000FF

class RGB
{
public:
	RGB(uint8_t S0_PIN, uint8_t S1_PIN, uint8_t S2_PIN, uint8_t S3_PIN, uint8_t out_PIN);
	int Getlevel(uint8_t type);
	void SetColor(int * Data);
private:
	uint8_t S0{};
	uint8_t S1{};
	uint8_t S2{};
	uint8_t S3{};
	uint8_t out{};
};

RGB::RGB(uint8_t S0_PIN, uint8_t S1_PIN, uint8_t S2_PIN, uint8_t S3_PIN, uint8_t out_PIN)
	: S0(S0_PIN), S1(S1_PIN), S2(S2_PIN), S3(S3_PIN), out(out_PIN)
{
	pinMode(this->S0, 1);
	pinMode(this->S1, 1);
	pinMode(this->S2, 1);
	pinMode(this->S3, 1);
	pinMode(this->out, 0);
	digitalWrite(this->S0, 1);
	digitalWrite(this->S1, 1);
}

int RGB::Getlevel(uint8_t type)
{
	switch (type)
	{
	case RED:
		digitalWrite(this->S2, 0);
		digitalWrite(this->S3, 0);
		break;
	case GREEN:
		digitalWrite(this->S2, 1);
		digitalWrite(this->S3, 1);
		break;
	case BLUE:
		digitalWrite(this->S2, 0);
		digitalWrite(this->S3, 1);
		break;
	default:
		digitalWrite(this->S2, 1);
		digitalWrite(this->S3, 0);
		break;
	}
	return pulseIn(this->out, 0);
}

void RGB::SetColor(int* Data)
{
	Data[1] = Getlevel(RED);
	Data[2] = Getlevel(GREEN);
	Data[3] = Getlevel(BLUE);
}
