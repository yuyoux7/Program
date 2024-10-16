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
	if constexpr (((sizeof...(L) % 2) == NULL) || (sizeof...(L) > 1))
	{
		being(Other...);
	}
};

template<typename C, typename ...L>
void IO<C, L...>::being(spio pin, L ...Other)
{
	Pin[pin] = pin;
	TYPE[pin] = BOTH;
	if constexpr (((sizeof...(L) % 2) == NULL) || (sizeof...(L) > 1))
	{
		being(Other...);
	}
};

template<typename C, typename ...L>
bool IO<C, L...>::write(spio pin, spio Power, L ...Other)
{
	if constexpr ((((sizeof...(L) % 2) == NULL) && signal(pin)))
	{
		//do something	
	}
	else if constexpr ((sizeof...(L) > 1 && signal(pin)))
	{
		//do something->same up
		write(Other...);
	}
	else
	{
		return false;
	}
	return true;
};

template<typename C, typename ...L>
C IO<C, L...>::read(spio pin, L ...Other)
{
	if constexpr (sizeof...(L) == NULL && signal(pin))
	{
		//do something	
	}
	else if (signal(pin))
	{
		//do something->same up
		read(Other...);
		return C();
	}
};

template<typename C, typename ...L>
IO<C, L...>::~IO()
{

};

template<typename C, typename ...L>
bool IO<C, L...>::signal(spio pin)
{
	C in_data{};
	C range{};
	if (Pin[pin] == pin)
	{
		return in_data >= range ? true : false;
	}
	return false;
};
