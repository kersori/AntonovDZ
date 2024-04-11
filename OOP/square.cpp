#include "square.h"

Square::Square(float a1)
{
	a = a1;
}

void Square::set_square(float a1)
{
	a = a1;
}

float Square::perimetr()
{
	return a * 4;
}

float Square::square()
{
	return a * a;
}