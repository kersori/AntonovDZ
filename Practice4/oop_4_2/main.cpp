#include "Atype.h"

using namespace std;

int main()
{	
	array <int> My_Int(5);

	for(int i = 0; i < 5; i++)
	{
		My_Int[i] = 5 - i;
	}

	cout << endl << "Неотсортированный массив" << endl;
	My_Int.Out();
	My_Int.Sort();
	cout << endl << "Отсортированный массив" << endl;
	My_Int.Out();

	array <string> My_String(5);
	My_String[0] = "Антонов";
	My_String[1] = "Ткачев";
	My_String[2] = "Князев";
	My_String[3] = "Андрейкин";
	My_String[4] = "Тютчев";
	
	cout << endl << "Неотсортированный массив" << endl;
	My_String.Out();
	My_String.Sort(My_String[0]);
	cout << endl << "Отсортированный массив" << endl;
	My_String.Out();
}
