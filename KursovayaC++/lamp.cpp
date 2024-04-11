#include "lamp.h"

Lamp::Lamp()
{
    button1 = 0;
    button2 = 0;
    lamp1 = 0;
    lamp2 = 0;
    lamp3 = 0;
}

void Lamp::Set_Ibutton1(int button)
{   
    button1 = button;
}

int Lamp::Get_Ibutton1()
{
    return button1;
}

void Lamp::Set_Ibutton2(int button)
{
    button2 = button;
}

int Lamp::Get_Ibutton2()
{
    return button2;
}

void Lamp::Set_Qlamp1(int lamp)
{
    lamp1 = lamp;
}

int Lamp::Get_Qlamp1()
{
    return lamp1;
}

void Lamp::Set_Qlamp2(int lamp)
{
    lamp2 = lamp;
}

int Lamp::Get_Qlamp2()
{
    return lamp2;
}
void Lamp::Set_Qlamp3(int lamp)
{
    lamp3 = lamp;
}

int Lamp::Get_Qlamp3()
{
    return lamp3;
}