#include <math.h>
#include <cmath>
#include <iostream>

class Circle
{
public:
	Circle(float r, float x, float y);
	void set_circle(float r, float x, float y);
	float square();
	bool triangle_around(float a, float b, float c);
	bool triangle_in(float a, float b, float c);
	bool check_circle(float r, float x_cntr, float y_cntr);

private:
	float radius;
	float x_center;
	float y_center;

protected:

};

class Triangle
{
public:
	Triangle(float a1, float b1, float c1);
	bool exst_tr();
	float perimetr();
	float square();

private:
	float a, b, c;

protected:

};