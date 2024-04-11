#include "rectangle.h"

Rectangle::Rectangle(float a1, float b1)
{
	a = a1;
	b = b1;
}

void Rectangle::set_rectangle(float a1, float b1)
{
	a = a1;
	b = b1;
}

float Rectangle::perimetr()
{
	return (a + b) * 2;
}

float Rectangle::square()
{
	return a * b;
}