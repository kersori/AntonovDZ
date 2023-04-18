#include <iostream>
#include <vector>
#include <string>
#include "ocean.h"

using namespace std;

Ocean::Ocean() : WaterArea() {}

Ocean::Ocean(string in_name, string in_location, double in_area, double in_size) : WaterArea(in_name, in_location, in_area, in_size) {}

Ocean::Ocean(string in_name, string in_location, double in_area, double in_size, WaterArea child_object) : WaterArea(in_name, in_location, in_area, in_size)
{
	add_child(child_object);
}

Ocean::Ocean(string in_name, string in_location, double in_area, double in_size, vector<WaterArea> child_objects) : WaterArea(in_name, in_location, in_area, in_size)
{
	add_childs(child_objects);
}

void Ocean::add_child(WaterArea child)
{
	child_water_areas.push_back(child);
}

void Ocean::add_childs(vector<WaterArea> childs)
{
	child_water_areas.insert(child_water_areas.end(), childs.begin(), childs.end());
}

vector<WaterArea> Ocean::get_childs()
{
	return child_water_areas;
}