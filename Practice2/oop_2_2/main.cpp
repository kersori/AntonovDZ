#include "rational.h"

using namespace std;

int main()
{   
    int n;
    int a, b;
    
    setlocale(LC_ALL, "Russian");

    cout << "Введите количество число дробей:  " << endl << "-> ";
    cin >> n;
    rational *mass = new rational[n];
    for(int i = 0; i < n; i++)
    {
        cout << "Введите числитель и знаменатель дроби №" << i+1 << " через пробел: " << endl << "-> ";
        cin >> a >> b;
        mass[i].set(a, b);
    }
    for(int i = 0; i < n; i++)
    {   
        mass[i].show(i);
    }
    delete mass;
}

