#include <iostream>
#include <vector>
#include <string>
#include "water.h"

using namespace std;

class Sea : public WaterArea
{
private:
	vector<WaterArea> parent_water_areas;
	vector<WaterArea> child_water_areas;

public:
	Sea();
	Sea(string in_name, string in_location, double in_area, double in_size);
	Sea(string in_name, string in_location, double in_area, double in_size, WaterArea parent_object, WaterArea child_object);

	void add_parent(WaterArea parent_object);
	void add_child(WaterArea child_object);
	void add_parents(vector<WaterArea> parent_objects);
	void add_childs(vector<WaterArea> child_objects);

	vector<WaterArea> get_parent_objects();
	vector<WaterArea> get_child_objects();

};
