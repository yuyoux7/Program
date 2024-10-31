#include "Arduino_IO.h"
template<typename C, typename ...L>
IO<C, L...>::IO()
{
};

template<typename C, typename ...L>
void IO<C, L...>::being(spio pin, type SP_TYPE, L ...Other)
{
	Pin[pin] = pin;
	TYPE[pin] = SP_TYPE;
	if constexpr (sizeof...(L) > NULL)
	{
		being(Other...);
	}
};

template<typename C, typename ...L>
void IO<C, L...>::being(spio pin, L ...Other)
{
	Pin[pin] = pin;
	TYPE[pin] = BOTH;
	if constexpr (sizeof...(L) > NULL)
	{
		being(Other...);
	}
};

template<typename C, typename ...L>
bool IO<C, L...>::write(spio pin, spio Power, L ...Other)
{
	if (signal(pin))
	{
		//do something
		if constexpr (sizeof...(L) > 1)
		{
			write(Other...)
		}
	}
	else
	{
		return false;
	}
	return true;
};

template<typename C, typename ...L>
C IO<C, L...>::read(spio pin)
{
	if (signal(pin))
	{
		//do something
	}
	return C(NULL);
};

template<typename C, typename ...L>
IO<C, L...>::~IO()
{

};

template<typename C, typename ...L>
bool IO<C, L...>::signal(spio pin)
{
	if (Pin[pin] == pin)
	{
		return TYPE[pin] == IN ? true : false;
	}
	return false;
};
