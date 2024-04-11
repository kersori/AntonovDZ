#include "privod.h"

Privod::Privod()
{
    privod1 = 0;
}

void Privod::Set_Q(int privod)
{   
    privod1 = privod;
}

int Privod::Get_Q()
{
    return privod1;
}