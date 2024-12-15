#pragma once
typedef uint8_t motor_pint;

class motor
{
public:
	motor(motor_pint ENA, motor_pint DIR, motor_pint PUI);
	void setstep(motor_pint step);
	void run(int turn);
	void back();
	void stop() const;
	~motor();

private:
	motor_pint ENA_pin{};
	motor_pint DIR_pin{};
	motor_pint PUI_pin{};
	motor_pint Run_F{};
	motor_pint Step{};
};

motor::motor(motor_pint ENA, motor_pint DIR, motor_pint PUI) : ENA_pin(ENA), DIR_pin(DIR), PUI_pin(PUI)
{
	pinMode(this->DIR_pin, 1);
	pinMode(this->PUI_pin, 1);
	pinMode(this->ENA_pin, 1);
	digitalWrite(this->PUI_pin, 0);
	digitalWrite(this->DIR_pin, 0);
	digitalWrite(this->ENA_pin, 1);
	digitalWrite(this->ENA_pin, 0);
	digitalWrite(this->DIR_pin, 1);
}

void motor::setstep(motor_pint step)
{
	this->Step = step;
}

void motor::run(int turn)
{
	this->Run_F = !turn;
	digitalWrite(this->ENA_pin, 0);
	digitalWrite(this->DIR_pin, turn);
	digitalWrite(this->PUI_pin, 1);
	delayMicroseconds(500);
	digitalWrite(this->PUI_pin, 0);
	delayMicroseconds(500);
}

void motor::back()
{
	digitalWrite(this->DIR_pin, this->Run_F);
	for (; this->Step > 0; this->Step--)
	{
		digitalWrite(this->PUI_pin, 1);
		delayMicroseconds(500);
		digitalWrite(this->PUI_pin, 0);
		delayMicroseconds(500);
	}
	stop();
}

void motor::stop() const
{
	digitalWrite(this->PUI_pin, 0);
	digitalWrite(this->ENA_pin, 1);
}

motor::~motor()
{

};