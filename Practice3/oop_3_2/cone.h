#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Cone
{
protected:
	double x, y, z;
	double radius, height;

public:
	Cone();

	Cone(double r, double h);

	Cone(double r, double h, double x1, double y1, double z1);

	void setCoordinate(double x1, double y1, double z1);

	void setRadius(double r);

	void setHeight(double h);

	void show();

	double area();

	double volume();

	friend ostream& operator<<(ostream& stream, Cone& obj)
	{
		stream << " (" << obj.x << "; ";
		stream << obj.y << "; ";
		stream << obj.z << "; ";
		stream << "r = " << obj.radius << "; ";
		stream << "h = " << obj.height << "; ";
		return stream;
	}

	double getHeight();

	double getRadius();

	double getX();

	double getY();

	double getZ();
};
