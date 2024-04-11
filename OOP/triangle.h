#include <math.h>
#include <cmath>
#include <iostream>

class Triangle
{
public:
	Triangle(float a1, float b1, float c1);
	bool exst_tr();
	float perimetr();
	float square();
    void set_triangle(float a, float b, float c);

private:
	float a, b, c;

protected:

};