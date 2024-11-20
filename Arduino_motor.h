#pragma once
typedef uint8_t motor_pint;

class motor
{
public:
	motor(motor_pint ENA, motor_pint DIR, motor_pint PUI);
	void setstep(motor_pint step);
	void run();
	void stop();
	~motor();

private:
	motor_pint ENA_pin{};
	motor_pint DIR_pin{};
	motor_pint PUI_pin{};
	motor_pint Step{};
};

motor::motor(motor_pint ENA, motor_pint DIR, motor_pint PUI) : ENA_pin(ENA), DIR_pin(DIR), PUI_pin(PUI)
{

}

void motor::setstep(motor_pint step)
{

}

void motor::run()
{

}

void motor::stop()
{

}

motor::~motor()
{

};