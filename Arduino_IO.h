#pragma once
#ifndef __ANDUINO_IO__
#define __ARDUINO_IO__
typedef uint8_t spio;
#define IN (spio) 0
#define OUT (spio) 1
#define BOTH (spio) 2
class IO
{
public:
	IO(spio fn = BOTH, spio PIN, ...);
	~IO();

private:

};
#endif