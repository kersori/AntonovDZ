#include <iostream>
#include <vector>
#include <string>
#include "water.h"

using namespace std;

class Ocean : public WaterArea
{
private:
	vector<WaterArea> child_water_areas;

public:
	Ocean();
	Ocean(WaterArea child_object);

	Ocean(string in_name, string in_location, double in_area, double in_size, WaterArea child_object);
	Ocean(string in_name, string in_location, double in_area, double in_size);
	Ocean(vector<WaterArea> child_objects);
	Ocean(string in_name, string in_location, double in_area, double in_size, vector<WaterArea> child_objects);

	vector<WaterArea> get_childs();

	void add_child(WaterArea child);
	void add_childs(vector<WaterArea> childs);
};