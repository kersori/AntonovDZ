#include "triangle.h"

Triangle::Triangle(float a1, float b1, float c1)
{
	a = a1;
	b = b1;
	c = c1;
}

void Triangle::set_triangle(float a1, float b1, float c1)
{
	a = a1;
	b = b1;
	c = c1;
}

bool Triangle::exst_tr()
{
	return a + b > c && a + c > b && b + c > a;
}

float Triangle::perimetr()
{
	return a + b + c;
}

float Triangle::square()
{
	float p = perimetr() / 2;
	return float(pow(p * (p - a) * (p - b) * (p - c), 0.5));
}