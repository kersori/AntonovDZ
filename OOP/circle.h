#include <math.h>
#include <cmath>
#include <iostream>
#include "form.h"

class Circle : public Form
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