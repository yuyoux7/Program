#pragma once

#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF

class RGB
{
public:
	RGB(uint8_t S0_PIN, uint8_t S1_PIN, uint8_t S2_PIN, uint8_t S3_PIN, uint8_t out_PIN);
	int Getlevel(uint8_t type);
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
	pinMode(S0, 1);
	pinMode(S1, 1);
	pinMode(S2, 1);
	pinMode(S3, 1);
	pinMode(out, 0);
	digitalWrite(S0, 1);
	digitalWrite(S1, 1);
}

int RGB::Getlevel(uint8_t type)
{
	switch (type)
	{
	case RED:
		digitalWrite(S2, 0);
		digitalWrite(S3, 0);
		break;
	case GREEN:
		digitalWrite(S2, 1);
		digitalWrite(S3, 1);
		break;
	case BLUE:
		digitalWrite(S2, 0);
		digitalWrite(S3, 1);
		break;
	default:
		digitalWrite(S2, 1);
		digitalWrite(S3, 0);
		break;
	}
	return pulseIn(out, 0);
}