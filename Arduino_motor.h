#pragma once
#if define(Arduino)
typedef uint16_t motor_pint;
#else
typedef int motor_pint;
#endif 

class motor
{
public:
	motor(motor_pint right, motor_pint left);
	~motor();

private:
	motor_pint right_pin{};
	motor_pint left_pin{};

};

motor::motor(motor_pint right, motor_pint left) : right_pin(right), left_pin(left)
{

};

motor::~motor()
{

};