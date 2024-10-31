#pragma once

class RGB
{
public:
	RGB(uint8_t S0_PIN, uint8_t S1_PIN, uint8_t S2_PIN, uint8_t S3_PIN, uint8_t out_PIN);
	int GetRedlevel();
	int GetBluelevel();
	int GetGreenlevel();
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

int RGB::GetRedlevel()
{
	digitalWrite(S2, 0);
	digitalWrite(S3, 0);
	return pulseIn(out, 0);
}

int RGB::GetBluelevel()
{
	digitalWrite(S2, 0);
	digitalWrite(S3, 1);
	return pulseIn(out, 0);
}

int RGB::GetGreenlevel()
{
	digitalWrite(S2, 1);
	digitalWrite(S3, 1);
	return pulseIn(out, 0);
}