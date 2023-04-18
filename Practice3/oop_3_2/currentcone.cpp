#include <iostream>
#include <cmath>
#include "currentcone.h"

using namespace std;

CurrentCone::CurrentCone()
{
	h2 = 1;
	r2 = 1;
}

CurrentCone::CurrentCone(double radius, double height, double radius2, double height2)
{
	set(radius, height, radius2, height2);
}

CurrentCone::CurrentCone(double radius, double height, double radius2, double height2, double x1, double y1, double z1)
{
	set(radius, height, radius2, height2, x1, y1, z1);
}

CurrentCone::CurrentCone(Cone cone)
{
	double radius2 = 1;
	double height2 = 1;
	set(cone.getRadius(), cone.getHeight(), radius2, height2, cone.getX(), cone.getY(), cone.getZ());
}

CurrentCone::CurrentCone(Cone cone, double radius2, double height2)
{
	set(cone.getRadius(), cone.getHeight(), radius2, height2, cone.getX(), cone.getY(), cone.getZ());
}

void CurrentCone::set(double radius, double height, double radius2, double height2)
{
	Cone::setRadius(radius);
	Cone::setHeight(height);
	h2 = height2;
	r2 = radius2;
}

void CurrentCone::set(double radius, double height, double radius2, double height2, double x1, double y1, double z1)
{
	Cone::setCoordinate(x1, y1, z1);
	Cone::setRadius(radius);
	Cone::setHeight(height);
	h2 = height2;
	r2 = radius2;
}

void CurrentCone::show()
{
	setlocale(LC_ALL, "Russian");
	cout << "Координаты основания x: " << x << " y: " << y << " z: " << z << endl;
	cout << "Высота полного конуса h: " << height << endl;
	cout << "Высота усеченного конуса h: " << h2 << endl;
	cout << "Радиус основания r: " << radius << endl;
	cout << "Радиус сечения r2: " << r2 << endl;
}

double CurrentCone::getArea()
{
	double full_area = Cone::area();
	double l = height - h2;
	return full_area - (3.14 * r2 * (r2 + sqrt(pow(r2, 2) + pow(l, 2))));
}

double CurrentCone::getVolume()
{
	double full_volume = Cone::volume();
	double l = height - h2;
	return full_volume - ((3.14 * pow(r2, 2) * l) / 3);

}

std::ostream& operator << (std::ostream& os, CurrentCone& cone)
{
	setlocale(LC_ALL, "Russian");
	return os << "Данные конуса" << endl
		<< "x: " << cone.getX() << endl
		<< "y: " << cone.getY() << endl
		<< "z: " << cone.getZ() << endl
		<< "r1: " << cone.getRadius() << endl
		<< "r2: " << cone.r2 << endl
		<< "h1: " << cone.getHeight() << endl
		<< "h2: " << cone.h2<< endl
		<< "Площадь конуса: " << cone.getArea() << endl
		<< "Объем конуса: " << cone.getVolume() << endl;
}

std::istream& operator >> (std::istream& in, CurrentCone& cone)
{
	double r, h, r2, h2, x, y, z;

	in >> r >> h >> r2 >> h2 >> x >> y >> z;
	cone.set(r, h, r2, h2, x, y, z);
	return in;
}

bool operator > (CurrentCone& cone1, CurrentCone& cone2)
{
	return cone1.getVolume() > cone2.getVolume();
}

bool operator < (CurrentCone& cone1, CurrentCone& cone2)
{
	return cone1.getVolume() < cone2.getVolume();
}

bool operator == (CurrentCone& cone1, CurrentCone& cone2)
{
	return cone1.getVolume() == cone2.getVolume();
}