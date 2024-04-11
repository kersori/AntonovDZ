#include <iostream>

using namespace std;

class Lamp
{
    int button1, button2, lamp1, lamp2, lamp3;

public:
    Lamp();
    int Get_Ibutton1();
    void Set_Ibutton1(int button);

    int Get_Ibutton2();
    void Set_Ibutton2(int button);

    int Get_Qlamp1();
    void Set_Qlamp1(int lamp);

    int Get_Qlamp2();
    void Set_Qlamp2(int lamp);

    int Get_Qlamp3();
    void Set_Qlamp3(int lamp);
};