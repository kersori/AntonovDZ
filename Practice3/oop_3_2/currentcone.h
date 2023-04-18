#pragma once
#include <iostream>
#include "cone.h"

using namespace std;

class CurrentCone : public Cone
{
private:
	double h2;
	double r2;

public:
	CurrentCone();

	CurrentCone(double radius, double height, double radius2, double height2);

	CurrentCone(double radius, double height, double radius2, double height2, double x1, double y1, double z1);

	CurrentCone(Cone cone);

	CurrentCone(Cone cone, double radius2, double height2);

	void set(double radius, double height, double radius2, double height2);

	void set(double radius, double height, double radius2, double height2, double x1, double y1, double z1);

	void show();

	double getArea();

	double getVolume();

	friend ostream& operator << (ostream& os, CurrentCone& cone);
	friend istream& operator >> (istream& in, CurrentCone& cone);

};


ostream& operator << (ostream& os, CurrentCone& cone);
istream& operator >> (istream& in, CurrentCone& cone);

bool operator > (CurrentCone& cone1, CurrentCone& cone2);
bool operator < (CurrentCone& cone1, CurrentCone& cone2);
bool operator == (CurrentCone& cone1, CurrentCone& cone2);

