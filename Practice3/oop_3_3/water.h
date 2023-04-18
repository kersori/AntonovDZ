#pragma once
#include <iostream>
#include <string>

using namespace std;

class WaterArea
{
protected:
	string name;
	string location;
	double area;
	double size;

public:
	WaterArea();
	WaterArea(string in_name, string in_location, double in_area, double in_size);

	string get_name();
	string get_location();

	double get_area();
	double get_size();

	void set_params(string in_name, string in_location, double in_area, double in_size);

	friend ostream& operator << (ostream& os, WaterArea& waterarea);
	friend istream& operator >> (istream& in, WaterArea& waterarea);
};

ostream& operator << (ostream& os, WaterArea& waterarea);
istream& operator >> (istream& in, WaterArea& waterarea);