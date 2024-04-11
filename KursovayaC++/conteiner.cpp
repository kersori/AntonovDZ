#include "conteiner.h"

Conteiner::Conteiner()
{
    conteiner1 = 0;
}

void Conteiner::Set_Q(int conteiner)
{
    conteiner1 = conteiner;
}

int Conteiner::Get_Q()
{
    return conteiner1;
}

void Conteiner::Set_N(int N)
{
    N1 = N;
}

int Conteiner::Get_N()
{
    return N1;
}