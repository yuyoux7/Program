#pragma once
#ifndef __ANDUINO_IO__
#define __ARDUINO_IO__
typedef uint16_t spio;
typedef uint8_t type;
#define IN (type) 0
#define OUT (type) 1
#define BOTH (type) 2
template <typename C, typename ...L>
class IO
{
	eunm{
		A0 = 15,
		A1 = 16,
		A2 = 17,
		A3 = 18,
		A4 = 19,
		A5 = 20
	};

public:
	IO();
	void being(spio pin, type SP_TYPE = BOTH, L ...Other);
	void being(spio pin, L ...Other);
	bool write(spio pin, spio Power, L ...Other);
	C read(spio pin, L ...Other);
	~IO();
	
private:
	bool signal(spio pin);
	spio Pin[30]{};
	type TYPE[30]{};

};
#endif