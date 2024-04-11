#include <iostream>
#include "lamp.h"
#include "conteiner.h"
#include "datchik.h"
#include "privod.h"
#include <cstdlib>
#include <windows.h>
#include <locale.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{   
    setlocale(LC_ALL, "Russian");

    int p1 = 0; // память
    int p2 = 0;
    int p3 = 0;

    int n; // количество деталей

    Conteiner conteiner1; // 4 контейнера
    Conteiner conteiner2;
    Conteiner conteiner3; 
    Conteiner conteiner4;

    Lamp lamp1; // пульт управления

    Datchik datchik1; // датчик, заготовка дошла до края ленты 1
    Datchik datchik2; // датчик, заготовка дошла до края ленты 2
    Datchik datchik3; // датчик, заготовка дошла до края ленты 3
    Datchik datchik4; // датчик, наличие заготовки в контейнере 1
    Datchik datchik5; // датчик, наличие заготовки в контейнере 2
    Datchik datchik6; // датчик, наличие заготовки в контейнере 3
    Datchik datchik7; // датчик, наполнений контейенра 4 с готовыми деталями
    Datchik datchik8; // датчик приближения заготовки к печати 1
    Datchik datchik9; // датчик приближения заготовки к печати 2
    Datchik datchik10; // датчик приближения заготовки к печати 3

    Privod privod1; // конвейерная лента, привод 1
    Privod privod2; // конвейерная лента, привод 2
    Privod privod3; // конвейерная лента, привод 3
    Privod privod4; // заслонка контейнера с заготовками, привод 1 НИЗ
    Privod privod5; // заслонка контейнера с заготовками, привод 2 НИЗ
    Privod privod6; // заслонка контейнера с заготовками, привод 3 НИЗ
    Privod privod7; // заслонка контейнера с пропечатанными заготовками, привод 2 ВЕРХ
    Privod privod8; // заслонка контейнера с пропечатанными заготовками, привод 3 ВЕРХ
    Privod privod9; // заслонка контейнера с пропечатанными заготовками, привод 4 ВЕРХ
    Privod privod10; // привод печати 1
    Privod privod11; // привод печати 2
    Privod privod12; // привод печати 3
    
    ifstream fin1("vhod.txt");

    ofstream fout1("vihod.txt");

    string buff;

    int mass1[21]{ 1, 2, 9, 15, 21, 27, 34, 6, 11, 17, 23, 28, 36, 7, 14, 20, 26, 30, 33, 40, 41 };
    int mass2[27]{ 1, 2, 9, 15, 21, 27, 34, 3, 10, 16, 22, 29, 35, 5, 13, 19, 25, 31, 38, 7, 14, 20, 26, 30, 33, 40, 41 };
    int mass3[33]{ 1, 2, 9, 15, 21, 27, 34, 3, 10, 16, 22, 29, 35, 8, 12, 18, 24, 32, 37, 5, 13, 19, 25, 31, 38, 7, 14, 20, 26, 30, 33, 40, 41 };

    while (true)
    {   
        cout << "Выберите сколько деталей будет храниться в контейнере: (для выхода из программы введите 0)" << endl;

        cin >> n;

        if (n == 0)
        {
            break;
        }

        conteiner1.Set_N(n);

        cout << endl;

        if (conteiner1.Get_N() == 1) // ------------------------------------ Одна деталь
        {   
            for (int j = 0; j < 21; j++)
            {   
                ifstream fin1("vhod.txt");
                ofstream fout1("vihod.txt", ios::app);

                const int line = mass1[j];
                for (int i = 1; i <= line; i++)
                {
                    getline(fin1, buff);
                }
                
                stringstream in(buff);
                vector<int> a;
                int temp;
                while (in >> temp)
                {
                    a.push_back(temp);
                }
                
                datchik1.Set_I(a[0]);
                datchik2.Set_I(a[1]);
                datchik3.Set_I(a[2]);
                datchik4.Set_I(a[3]);
                datchik5.Set_I(a[4]);
                datchik6.Set_I(a[5]);
                datchik7.Set_I(a[6]);
                datchik8.Set_I(a[7]);
                datchik9.Set_I(a[8]);
                datchik10.Set_I(a[9]);

                lamp1.Set_Ibutton1(a[10]);
                lamp1.Set_Ibutton2(a[11]);

                privod1.Set_Q(0);
                privod2.Set_Q(0);
                privod3.Set_Q(0);
                privod4.Set_Q(0);
                privod5.Set_Q(0);
                privod6.Set_Q(0);
                privod7.Set_Q(0);
                privod8.Set_Q(0);
                privod9.Set_Q(0);
                privod10.Set_Q(0);
                privod11.Set_Q(0);
                privod12.Set_Q(0);

                lamp1.Set_Qlamp1(0);
                lamp1.Set_Qlamp2(0);
                lamp1.Set_Qlamp3(0);

                if (mass1[j] == 1)
                {
                    if (lamp1.Get_Ibutton1() == 1)
                    {
                        privod1.Set_Q(1);
                    }
                }

                else if (mass1[j] > 1 && 9 > mass1[j])
                {   
                    p1 = a[3];
                    p2 = a[4];
                    p3 = a[5];

                    if (datchik4.Get_I() == 1)
                    {
                        privod1.Set_Q(1);
                        privod4.Set_Q(1);
                    }
                    if (p1 == 0 && p2 == 0 && p3 == 0)
                    {
                        lamp1.Set_Qlamp1(1);
                        lamp1.Set_Qlamp3(1);
                    }
                    if (datchik5.Get_I() == 1)
                    {
                        privod2.Set_Q(1);
                        privod5.Set_Q(1);
                    }
                    if (datchik6.Get_I() == 1)
                    {
                        privod3.Set_Q(1);
                        privod6.Set_Q(1);
                    }
                }

                else if (mass1[j] > 8 && 15 > mass1[j])
                {
                    if (p1 == 1 && p2 == 0 && p3 == 0)
                    {
                        privod1.Set_Q(1);
                    }
                    if (p1 == 0 && p2 == 1 && p3 == 0)
                    {
                        privod2.Set_Q(1);
                    }
                    if (p1 == 0 && p2 == 0 && p3 == 1)
                    {
                        privod3.Set_Q(1);
                    }
                }

                else if (mass1[j] > 14 && 21 > mass1[j])
                {
                    if (datchik8.Get_I() == 1)
                    {
                        privod1.Set_Q(1);
                        privod10.Set_Q(1);
                    }
                    if (datchik9.Get_I() == 1)
                    {
                        privod2.Set_Q(1);
                        privod11.Set_Q(1);
                    }
                    if (datchik10.Get_I() == 1)
                    {
                        privod3.Set_Q(1);
                        privod12.Set_Q(1);
                    }
                }

                else if (mass1[j] > 20 && 27 > mass1[j])
                {
                    if (p1 == 1 && p2 == 0 && p3 == 0)
                    {
                        privod1.Set_Q(1);
                    }
                    if (p1 == 0 && p2 == 1 && p3 == 0)
                    {
                        privod2.Set_Q(1);
                    }
                    if (p1 == 0 && p2 == 0 && p3 == 1)
                    {
                        privod3.Set_Q(1);
                    }
                }

                else if (mass1[j] > 26 && 33 > mass1[j])
                {
                    if (datchik1.Get_I() == 1)
                    {
                        privod1.Set_Q(1);
                        privod2.Set_Q(1);
                        privod7.Set_Q(1);
                    }
                    if (datchik2.Get_I() == 1)
                    {
                        privod2.Set_Q(1);
                        privod3.Set_Q(1);
                        privod8.Set_Q(1);
                    }
                    if (datchik3.Get_I() == 1)
                    {
                        privod3.Set_Q(1);
                        privod9.Set_Q(1);
                    }
                }

                else if (mass1[j] > 32 && 40 > mass1[j])
                {   
                    if (datchik7.Get_I() == 1)
                    {
                        lamp1.Set_Qlamp2(1);
                        lamp1.Set_Qlamp3(1);
                    }
                    if (p1 == 1 && p2 == 0 && p3 == 0 && datchik7.Get_I() == 0)
                    {
                        privod1.Set_Q(1);
                        privod2.Set_Q(1);
                    }
                    if (p1 == 0 && p2 == 1 && p3 == 0 && datchik7.Get_I() == 0)
                    {
                        privod2.Set_Q(1);
                        privod3.Set_Q(1);
                    }
                    if (p1 == 0 && p2 == 0 && p3 == 1 && datchik7.Get_I() == 0)
                    {
                        privod3.Set_Q(1);
                    }
                }

                else if (mass1[j] == 40)
                {
                    if (lamp1.Get_Ibutton2() == 1)
                    {
                        
                    }
                }

                else
                {   
                    lamp1.Set_Qlamp3(1);
                }

                cout << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                    << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                    << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                    << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                fout1 << datchik1.Get_I() << " " << datchik2.Get_I() << " " << datchik3.Get_I() << " " << datchik4.Get_I() << " "
                    << datchik5.Get_I() << " " << datchik6.Get_I() << " " << datchik7.Get_I() << " " << datchik8.Get_I() << " "
                    << datchik9.Get_I() << " " << datchik10.Get_I() << " " << lamp1.Get_Ibutton1() << " " << lamp1.Get_Ibutton2()
                    << " || " << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                    << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                    << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                    << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                fin1.close(); // закрываем файл
                fout1.close(); // закрываем файл
            }

            cout << endl;
        }

        else if (conteiner1.Get_N() == 2) // ------------------------------------ Две детали
        {
            for (int j = 0; j < 27; j++)
            {   
                ifstream fin1("vhod.txt");
                ofstream fout1("vihod.txt", ios::app);

                const int line = mass2[j];
                for (int i = 1; i <= line; i++)
                {
                    getline(fin1, buff);
                }
                
                stringstream in(buff);
                vector<int> a;
                int temp;
                while (in >> temp)
                {
                    a.push_back(temp);
                }
                
                datchik1.Set_I(a[0]);
                datchik2.Set_I(a[1]);
                datchik3.Set_I(a[2]);
                datchik4.Set_I(a[3]);
                datchik5.Set_I(a[4]);
                datchik6.Set_I(a[5]);
                datchik7.Set_I(a[6]);
                datchik8.Set_I(a[7]);
                datchik9.Set_I(a[8]);
                datchik10.Set_I(a[9]);

                lamp1.Set_Ibutton1(a[10]);
                lamp1.Set_Ibutton2(a[11]);

                privod1.Set_Q(0);
                privod2.Set_Q(0);
                privod3.Set_Q(0);
                privod4.Set_Q(0);
                privod5.Set_Q(0);
                privod6.Set_Q(0);
                privod7.Set_Q(0);
                privod8.Set_Q(0);
                privod9.Set_Q(0);
                privod10.Set_Q(0);
                privod11.Set_Q(0);
                privod12.Set_Q(0);

                lamp1.Set_Qlamp1(0);
                lamp1.Set_Qlamp2(0);
                lamp1.Set_Qlamp3(0);

                if (mass2[j] == 1)
                {
                    if (lamp1.Get_Ibutton1() == 1)
                    {
                        privod1.Set_Q(1);
                    }
                }

                else if (mass2[j] > 1 && 9 > mass2[j])
                {   
                    p1 = a[3];
                    p2 = a[4];
                    p3 = a[5];

                    if (datchik4.Get_I() == 1 && datchik5.Get_I() == 0 && datchik6.Get_I() == 0)
                    {
                        privod1.Set_Q(1);
                        privod4.Set_Q(1);
                    }
                    if (p1 == 0 && p2 == 0 && p3 == 0)
                    {
                        lamp1.Set_Qlamp1(1);
                        lamp1.Set_Qlamp3(1);
                    }
                    if (datchik4.Get_I() == 0 && datchik5.Get_I() == 0 && datchik6.Get_I() == 1)
                    {
                        privod3.Set_Q(1);
                        privod6.Set_Q(1);
                    }
                    if (datchik4.Get_I() == 1 && datchik5.Get_I() == 1 && datchik6.Get_I() == 0)
                    {
                        privod1.Set_Q(1);
                        privod4.Set_Q(1);
                        privod2.Set_Q(1);
                        privod5.Set_Q(1);
                    }
                    if (datchik4.Get_I() == 0 && datchik5.Get_I() == 1 && datchik6.Get_I() == 1)
                    {
                        privod2.Set_Q(1);
                        privod5.Set_Q(1);
                        privod3.Set_Q(1);
                        privod6.Set_Q(1);
                    }
                }

                else if (mass2[j] > 8 && 15 > mass2[j])
                {
                    if (p1 == 1 && p2 == 0 && p3 == 0)
                    {
                        privod1.Set_Q(1);
                    }
                    if (p1 == 1 && p2 == 1 && p3 == 0)
                    {
                        privod1.Set_Q(1);
                        privod2.Set_Q(1);
                    }
                    if (p1 == 0 && p2 == 1 && p3 == 1)
                    {
                        privod2.Set_Q(1);
                        privod3.Set_Q(1);
                    }
                    if (p1 == 0 && p2 == 0 && p3 == 1)
                    {
                        privod3.Set_Q(1);
                    }
                }

                else if (mass2[j] > 14 && 21 > mass2[j])
                {
                    if (datchik8.Get_I() == 1 && datchik9.Get_I() == 0 && datchik10.Get_I() == 0)
                    {
                        privod1.Set_Q(1);
                        privod10.Set_Q(1);
                    }
                    if (datchik8.Get_I() == 1 && datchik9.Get_I() == 1 && datchik10.Get_I() == 0)
                    {   
                        privod1.Set_Q(1);
                        privod10.Set_Q(1);
                        privod2.Set_Q(1);
                        privod11.Set_Q(1);
                    }
                    if (datchik8.Get_I() == 0 && datchik9.Get_I() == 1 && datchik10.Get_I() == 1)
                    {
                        privod2.Set_Q(1);
                        privod11.Set_Q(1);
                        privod3.Set_Q(1);
                        privod12.Set_Q(1);
                    }
                    if (datchik8.Get_I() == 0 && datchik9.Get_I() == 0 && datchik10.Get_I() == 1)
                    {
                        privod3.Set_Q(1);
                        privod12.Set_Q(1);
                    }
                }

                else if (mass2[j] > 20 && 27 > mass2[j])
                {
                    if (p1 == 1 && p2 == 0 && p3 == 0)
                    {
                        privod1.Set_Q(1);
                    }
                    if (p1 == 1 && p2 == 1 && p3 == 0)
                    {
                        privod1.Set_Q(1);
                        privod2.Set_Q(1);
                    }
                    if (p1 == 0 && p2 == 1 && p3 == 1)
                    {
                        privod2.Set_Q(1);
                        privod3.Set_Q(1);
                    }
                    if (p1 == 0 && p2 == 0 && p3 == 1)
                    {
                        privod3.Set_Q(1);
                    }
                }

                else if (mass2[j] > 26 && 33 > mass2[j])
                {
                    if (datchik1.Get_I() == 1 && datchik2.Get_I() == 0 && datchik3.Get_I() == 0)
                    {
                        privod1.Set_Q(1);
                        privod2.Set_Q(1);
                        privod7.Set_Q(1);
                    }
                    if (datchik1.Get_I() == 1 && datchik2.Get_I() == 1 && datchik3.Get_I() == 0)
                    {
                        privod1.Set_Q(1);
                        privod2.Set_Q(1);
                        privod7.Set_Q(1);
                        privod2.Set_Q(1);
                        privod3.Set_Q(1);
                        privod8.Set_Q(1);
                    }
                    if (datchik1.Get_I() == 0 && datchik2.Get_I() == 1 && datchik3.Get_I() == 1)
                    {
                        privod2.Set_Q(1);
                        privod3.Set_Q(1);
                        privod8.Set_Q(1);
                        privod3.Set_Q(1);
                        privod9.Set_Q(1);
                    }
                    if (datchik1.Get_I() == 0 && datchik2.Get_I() == 0 && datchik3.Get_I() == 1)
                    {
                        privod3.Set_Q(1);
                        privod9.Set_Q(1);
                    }
                }

                else if (mass2[j] > 32 && 40 > mass2[j])
                {   
                    if (datchik7.Get_I() == 1)
                    {
                        lamp1.Set_Qlamp2(1);
                        lamp1.Set_Qlamp3(1);
                    }
                    if (p1 == 1 && p2 == 0 && p3 == 0 && datchik7.Get_I() == 0)
                    {
                        privod1.Set_Q(1);
                        privod2.Set_Q(1);
                    }
                    if (p1 == 1 && p2 == 1 && p3 == 0 && datchik7.Get_I() == 0)
                    {
                        privod1.Set_Q(1);
                        privod2.Set_Q(1);
                        privod3.Set_Q(1);
                    }
                    if (p1 == 0 && p2 == 1 && p3 == 1 && datchik7.Get_I() == 0)
                    {
                        privod2.Set_Q(1);
                        privod3.Set_Q(1);
                    }
                    if (p1 == 0 && p2 == 0 && p3 == 1 && datchik7.Get_I() == 0)
                    {
                        privod3.Set_Q(1);
                    }
                }

                else if (mass2[j] == 40)
                {
                    if (lamp1.Get_Ibutton2() == 1)
                    {
                        
                    }
                }

                else
                {   
                    lamp1.Set_Qlamp3(1);
                }

                cout << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                    << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                    << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                    << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                fout1 << datchik1.Get_I() << " " << datchik2.Get_I() << " " << datchik3.Get_I() << " " << datchik4.Get_I() << " "
                    << datchik5.Get_I() << " " << datchik6.Get_I() << " " << datchik7.Get_I() << " " << datchik8.Get_I() << " "
                    << datchik9.Get_I() << " " << datchik10.Get_I() << " " << lamp1.Get_Ibutton1() << " " << lamp1.Get_Ibutton2()
                    << " || " << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                    << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                    << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                    << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                fin1.close(); // закрываем файл
                fout1.close(); // закрываем файл
            }

            cout << endl;
        }

        //int mass3[33]{ 1, 2, 9, 15, 21, 27, 34, 3, 10, 16, 22, 29, 35, 8, 12, 18, 24, 32, 37, 5, 13, 19, 25, 31, 38, 7, 14, 20, 26, 30, 33, 40, 41 };
        else if (conteiner1.Get_N() >= 3)  // ------------------------------------ Три и более детали
        {
            vector<int> vector1;

            for (int i = 0; i < 19; i++)
            {
                vector1.push_back(mass3[i]);
            }
            if (conteiner1.Get_N() > 3)
            {
                int minus = conteiner1.Get_N() - 3;
                for (int i = 0; i < minus; i++)
                {
                    for (int g = 14; g < 19; g++)
                    {
                        vector1.push_back(mass3[g]);
                    }
                }
            }
            for (int i = 19; i < 33; i++)
            {
                vector1.push_back(mass3[i]);
            }

            for (int j = 0; j < vector1.size(); j++)
            {
                ifstream fin1("vhod.txt");
                ofstream fout1("vihod.txt", ios::app);

                const int line = vector1[j];
                for (int i = 1; i <= line; i++)
                {
                    getline(fin1, buff);
                }

                stringstream in(buff);
                vector<int> a;
                int temp;
                while (in >> temp)
                {
                    a.push_back(temp);
                }

                datchik1.Set_I(a[0]);
                datchik2.Set_I(a[1]);
                datchik3.Set_I(a[2]);
                datchik4.Set_I(a[3]);
                datchik5.Set_I(a[4]);
                datchik6.Set_I(a[5]);
                datchik7.Set_I(a[6]);
                datchik8.Set_I(a[7]);
                datchik9.Set_I(a[8]);
                datchik10.Set_I(a[9]);

                lamp1.Set_Ibutton1(a[10]);
                lamp1.Set_Ibutton2(a[11]);

                privod1.Set_Q(0);
                privod2.Set_Q(0);
                privod3.Set_Q(0);
                privod4.Set_Q(0);
                privod5.Set_Q(0);
                privod6.Set_Q(0);
                privod7.Set_Q(0);
                privod8.Set_Q(0);
                privod9.Set_Q(0);
                privod10.Set_Q(0);
                privod11.Set_Q(0);
                privod12.Set_Q(0);

                lamp1.Set_Qlamp1(0);
                lamp1.Set_Qlamp2(0);
                lamp1.Set_Qlamp3(0);

                if (vector1[j] == 1)
                {
                    if (lamp1.Get_Ibutton1() == 1)
                    {
                        privod1.Set_Q(1);
                    }

                    cout << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                        << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                        << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                        << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                    fout1 << datchik1.Get_I() << " " << datchik2.Get_I() << " " << datchik3.Get_I() << " " << datchik4.Get_I() << " "
                        << datchik5.Get_I() << " " << datchik6.Get_I() << " " << datchik7.Get_I() << " " << datchik8.Get_I() << " "
                        << datchik9.Get_I() << " " << datchik10.Get_I() << " " << lamp1.Get_Ibutton1() << " " << lamp1.Get_Ibutton2()
                        << " || " << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                        << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                        << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                        << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                    fin1.close(); // закрываем файл
                    fout1.close(); // закрываем файл
            }
            
            else if (vector1[j] > 1 && 9 > vector1[j])
            {
                p1 = a[3];
                p2 = a[4];
                p3 = a[5];

                if (datchik4.Get_I() == 1 && datchik5.Get_I() == 0 && datchik6.Get_I() == 0)
                {
                    privod1.Set_Q(1);
                    privod4.Set_Q(1);
                }
                if (p1 == 0 && p2 == 0 && p3 == 0)
                {
                    lamp1.Set_Qlamp1(1);
                    lamp1.Set_Qlamp3(1);
                }
                if (datchik4.Get_I() == 0 && datchik5.Get_I() == 0 && datchik6.Get_I() == 1)
                {
                    privod3.Set_Q(1);
                    privod6.Set_Q(1);
                }
                if (datchik4.Get_I() == 1 && datchik5.Get_I() == 1 && datchik6.Get_I() == 0)
                {
                    privod1.Set_Q(1);
                    privod4.Set_Q(1);
                    privod2.Set_Q(1);
                    privod5.Set_Q(1);
                }
                if (datchik4.Get_I() == 0 && datchik5.Get_I() == 1 && datchik6.Get_I() == 1)
                {
                    privod2.Set_Q(1);
                    privod5.Set_Q(1);
                    privod3.Set_Q(1);
                    privod6.Set_Q(1);
                }
                if (datchik4.Get_I() == 1 && datchik5.Get_I() == 1 && datchik6.Get_I() == 1)
                {   
                    privod1.Set_Q(1);
                    privod4.Set_Q(1);
                    privod2.Set_Q(1);
                    privod5.Set_Q(1);
                    privod3.Set_Q(1);
                    privod6.Set_Q(1);
                }

                cout << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                    << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                    << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                    << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                fout1 << datchik1.Get_I() << " " << datchik2.Get_I() << " " << datchik3.Get_I() << " " << datchik4.Get_I() << " "
                    << datchik5.Get_I() << " " << datchik6.Get_I() << " " << datchik7.Get_I() << " " << datchik8.Get_I() << " "
                    << datchik9.Get_I() << " " << datchik10.Get_I() << " " << lamp1.Get_Ibutton1() << " " << lamp1.Get_Ibutton2()
                    << " || " << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                    << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                    << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                    << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                fin1.close(); // закрываем файл
                fout1.close(); // закрываем файл
            }

            else if (vector1[j] > 8 && 15 > vector1[j])
            {
                if (p1 == 1 && p2 == 0 && p3 == 0)
                {
                    privod1.Set_Q(1);
                }
                if (p1 == 1 && p2 == 1 && p3 == 0)
                {
                    privod1.Set_Q(1);
                    privod2.Set_Q(1);
                }
                if (p1 == 0 && p2 == 1 && p3 == 1)
                {
                    privod2.Set_Q(1);
                    privod3.Set_Q(1);
                }
                if (p1 == 0 && p2 == 0 && p3 == 1)
                {
                    privod3.Set_Q(1);
                }
                if (p1 == 1 && p2 == 1 && p3 == 1)
                {   
                    privod1.Set_Q(1);
                    privod2.Set_Q(1);
                    privod3.Set_Q(1);
                }

                cout << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                    << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                    << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                    << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                fout1 << datchik1.Get_I() << " " << datchik2.Get_I() << " " << datchik3.Get_I() << " " << datchik4.Get_I() << " "
                    << datchik5.Get_I() << " " << datchik6.Get_I() << " " << datchik7.Get_I() << " " << datchik8.Get_I() << " "
                    << datchik9.Get_I() << " " << datchik10.Get_I() << " " << lamp1.Get_Ibutton1() << " " << lamp1.Get_Ibutton2()
                    << " || " << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                    << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                    << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                    << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                fin1.close(); // закрываем файл
                fout1.close(); // закрываем файл
            }

            else if (vector1[j] > 14 && 21 > vector1[j])
            {
                if (datchik8.Get_I() == 1 && datchik9.Get_I() == 0 && datchik10.Get_I() == 0)
                {
                    privod1.Set_Q(1);
                    privod10.Set_Q(1);
                }
                if (datchik8.Get_I() == 1 && datchik9.Get_I() == 1 && datchik10.Get_I() == 0)
                {
                    privod1.Set_Q(1);
                    privod10.Set_Q(1);
                    privod2.Set_Q(1);
                    privod11.Set_Q(1);
                }
                if (datchik8.Get_I() == 0 && datchik9.Get_I() == 1 && datchik10.Get_I() == 1)
                {
                    privod2.Set_Q(1);
                    privod11.Set_Q(1);
                    privod3.Set_Q(1);
                    privod12.Set_Q(1);
                }
                if (datchik8.Get_I() == 0 && datchik9.Get_I() == 0 && datchik10.Get_I() == 1)
                {
                    privod3.Set_Q(1);
                    privod12.Set_Q(1);
                }
                if (datchik8.Get_I() == 1 && datchik9.Get_I() == 1 && datchik10.Get_I() == 1)
                {   
                    privod1.Set_Q(1);
                    privod10.Set_Q(1);
                    privod2.Set_Q(1);
                    privod11.Set_Q(1);
                    privod3.Set_Q(1);
                    privod12.Set_Q(1);
                }

                cout << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                    << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                    << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                    << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                fout1 << datchik1.Get_I() << " " << datchik2.Get_I() << " " << datchik3.Get_I() << " " << datchik4.Get_I() << " "
                    << datchik5.Get_I() << " " << datchik6.Get_I() << " " << datchik7.Get_I() << " " << datchik8.Get_I() << " "
                    << datchik9.Get_I() << " " << datchik10.Get_I() << " " << lamp1.Get_Ibutton1() << " " << lamp1.Get_Ibutton2()
                    << " || " << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                    << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                    << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                    << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                fin1.close(); // закрываем файл
                fout1.close(); // закрываем файл
            }

            else if (vector1[j] > 20 && 27 > vector1[j])
            {
                if (p1 == 1 && p2 == 0 && p3 == 0)
                {
                    privod1.Set_Q(1);
                }
                if (p1 == 1 && p2 == 1 && p3 == 0)
                {
                    privod1.Set_Q(1);
                    privod2.Set_Q(1);
                }
                if (p1 == 0 && p2 == 1 && p3 == 1)
                {
                    privod2.Set_Q(1);
                    privod3.Set_Q(1);
                }
                if (p1 == 0 && p2 == 0 && p3 == 1)
                {
                    privod3.Set_Q(1);
                }
                if (p1 == 1 && p2 == 1 && p3 == 1)
                {   
                    privod1.Set_Q(1);
                    privod2.Set_Q(1);
                    privod3.Set_Q(1);
                }

                cout << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                    << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                    << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                    << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                fout1 << datchik1.Get_I() << " " << datchik2.Get_I() << " " << datchik3.Get_I() << " " << datchik4.Get_I() << " "
                    << datchik5.Get_I() << " " << datchik6.Get_I() << " " << datchik7.Get_I() << " " << datchik8.Get_I() << " "
                    << datchik9.Get_I() << " " << datchik10.Get_I() << " " << lamp1.Get_Ibutton1() << " " << lamp1.Get_Ibutton2()
                    << " || " << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                    << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                    << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                    << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                fin1.close(); // закрываем файл
                fout1.close(); // закрываем файл
            }

            else if (vector1[j] > 26 && 33 > vector1[j])
            {
                if (datchik1.Get_I() == 1 && datchik2.Get_I() == 0 && datchik3.Get_I() == 0)
                {
                    privod1.Set_Q(1);
                    privod2.Set_Q(1);
                    privod7.Set_Q(1);
                }
                if (datchik1.Get_I() == 1 && datchik2.Get_I() == 1 && datchik3.Get_I() == 0)
                {
                    privod1.Set_Q(1);
                    privod2.Set_Q(1);
                    privod7.Set_Q(1);
                    privod2.Set_Q(1);
                    privod3.Set_Q(1);
                    privod8.Set_Q(1);
                }
                if (datchik1.Get_I() == 0 && datchik2.Get_I() == 1 && datchik3.Get_I() == 1)
                {
                    privod2.Set_Q(1);
                    privod3.Set_Q(1);
                    privod8.Set_Q(1);
                    privod3.Set_Q(1);
                    privod9.Set_Q(1);
                }
                if (datchik1.Get_I() == 0 && datchik2.Get_I() == 0 && datchik3.Get_I() == 1)
                {
                    privod3.Set_Q(1);
                    privod9.Set_Q(1);
                }
                if (datchik1.Get_I() == 1 && datchik2.Get_I() == 1 && datchik3.Get_I() == 1)
                {
                    privod1.Set_Q(1);
                    privod2.Set_Q(1);
                    privod7.Set_Q(1);
                    privod2.Set_Q(1);
                    privod3.Set_Q(1);
                    privod8.Set_Q(1);
                    privod3.Set_Q(1);
                    privod9.Set_Q(1);
                }

                cout << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                    << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                    << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                    << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                fout1 << datchik1.Get_I() << " " << datchik2.Get_I() << " " << datchik3.Get_I() << " " << datchik4.Get_I() << " "
                    << datchik5.Get_I() << " " << datchik6.Get_I() << " " << datchik7.Get_I() << " " << datchik8.Get_I() << " "
                    << datchik9.Get_I() << " " << datchik10.Get_I() << " " << lamp1.Get_Ibutton1() << " " << lamp1.Get_Ibutton2()
                    << " || " << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                    << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                    << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                    << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                fin1.close(); // закрываем файл
                fout1.close(); // закрываем файл
            }

            else if (vector1[j] > 32 && 40 > vector1[j])
            {
                if (datchik7.Get_I() == 1)
                {
                    lamp1.Set_Qlamp2(1);
                    lamp1.Set_Qlamp3(1);
                }
                if (p1 == 1 && p2 == 0 && p3 == 0 && datchik7.Get_I() == 0)
                {
                    privod1.Set_Q(1);
                    privod2.Set_Q(1);
                }
                if (p1 == 1 && p2 == 1 && p3 == 0 && datchik7.Get_I() == 0)
                {
                    privod1.Set_Q(1);
                    privod2.Set_Q(1);
                    privod3.Set_Q(1);
                }
                if (p1 == 0 && p2 == 1 && p3 == 1 && datchik7.Get_I() == 0)
                {
                    privod2.Set_Q(1);
                    privod3.Set_Q(1);
                }
                if (p1 == 0 && p2 == 0 && p3 == 1 && datchik7.Get_I() == 0)
                {
                    privod3.Set_Q(1);
                }
                if (p1 == 1 && p2 == 1 && p3 == 1 && datchik7.Get_I() == 0)
                {   
                    privod1.Set_Q(1);
                    privod2.Set_Q(1);
                    privod3.Set_Q(1);
                }

                cout << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                    << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                    << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                    << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                fout1 << datchik1.Get_I() << " " << datchik2.Get_I() << " " << datchik3.Get_I() << " " << datchik4.Get_I() << " "
                    << datchik5.Get_I() << " " << datchik6.Get_I() << " " << datchik7.Get_I() << " " << datchik8.Get_I() << " "
                    << datchik9.Get_I() << " " << datchik10.Get_I() << " " << lamp1.Get_Ibutton1() << " " << lamp1.Get_Ibutton2()
                    << " || " << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                    << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                    << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                    << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                fin1.close(); // закрываем файл
                fout1.close(); // закрываем файл
            }

            else if (vector1[j] == 40)
            {
                if (lamp1.Get_Ibutton2() == 1)
                {

                }
                cout << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                    << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                    << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                    << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                fout1 << datchik1.Get_I() << " " << datchik2.Get_I() << " " << datchik3.Get_I() << " " << datchik4.Get_I() << " "
                    << datchik5.Get_I() << " " << datchik6.Get_I() << " " << datchik7.Get_I() << " " << datchik8.Get_I() << " "
                    << datchik9.Get_I() << " " << datchik10.Get_I() << " " << lamp1.Get_Ibutton1() << " " << lamp1.Get_Ibutton2()
                    << " || " << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                    << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                    << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                    << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                fin1.close(); // закрываем файл
                fout1.close(); // закрываем файл
            }

            else
            {
                lamp1.Set_Qlamp3(1);

                cout << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                    << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                    << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                    << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                fout1 << datchik1.Get_I() << " " << datchik2.Get_I() << " " << datchik3.Get_I() << " " << datchik4.Get_I() << " "
                    << datchik5.Get_I() << " " << datchik6.Get_I() << " " << datchik7.Get_I() << " " << datchik8.Get_I() << " "
                    << datchik9.Get_I() << " " << datchik10.Get_I() << " " << lamp1.Get_Ibutton1() << " " << lamp1.Get_Ibutton2()
                    << " || " << privod1.Get_Q() << " " << privod2.Get_Q() << " " << privod3.Get_Q() << " " << privod4.Get_Q()
                    << " " << privod5.Get_Q() << " " << privod6.Get_Q() << " " << privod7.Get_Q() << " " << privod8.Get_Q()
                    << " " << privod9.Get_Q() << " " << privod10.Get_Q() << " " << privod11.Get_Q() << " " << privod12.Get_Q()
                    << " " << lamp1.Get_Qlamp1() << " " << lamp1.Get_Qlamp2() << " " << lamp1.Get_Qlamp3() << endl;

                fin1.close(); // закрываем файл
                fout1.close(); // закрываем файл
            }

        }

        cout << endl;
        }

        else
        {
            cout << "Неверный ввод" << endl << endl;
        }
    }
}
/*-----------В случае одного конвейера----------
I0 - датчик, заготовка дошла до края ленты
I1 - датчик, наличие заготовки в контейнере
I2 - датчик, наполнений контейенра с готовыми деталями
I3 - датчик приближения заготовки к печати
I4 - кнопка старта
I5 - кнопка экстренной остановки

Q0 - конвейерная лента, привод
Q1 - заслонка контейнера с заготовками НИЗ
Q2 - заслонка контейнера с пропечатанными заготовками ВЕРХ
Q3 - привод печати
Q6 - лампочка, заготовки закончились
Q7 - лампочка, контейнер для проечатанных заготовок полон
Q8 - лампочка аварийного состояния

-------------В случае 3 конвейеров--------------
i01 - датчик, заготовка дошла до края ленты 1
i02 - датчик, заготовка дошла до края ленты 2
i03 - датчик, заготовка дошла до края ленты 3

i11 - датчик, наличие заготовки в контейнере 1
i12 - датчик, наличие заготовки в контейнере 2
i13 - датчик, наличие заготовки в контейнере 3

i24 - датчик, наполнений контейенра 4 с готовыми деталями

i31 - датчик приближения заготовки к печати 1
i32 - датчик приближения заготовки к печати 2
i33 - датчик приближения заготовки к печати 3

i4 - кнопка старта
i5 - кнопка экстренной остановки

q01 - конвейерная лента, привод 1
q02 - конвейерная лента, привод 2
q03 - конвейерная лента, привод 3

q11 - заслонка контейнера с заготовками, привод 1 НИЗ
q12 - заслонка контейнера с заготовками, привод 2 НИЗ
q13 - заслонка контейнера с заготовками, привод 3 НИЗ

q22 - заслонка контейнера с пропечатанными заготовками, привод 2 ВЕРХ
q23 - заслонка контейнера с пропечатанными заготовками, привод 3 ВЕРХ
q24 - заслонка контейнера с пропечатанными заготовками, привод 4 ВЕРХ

q31 - привод печати 1
q32 - привод печати 2
q33 - привод печати 3

q6 - лампочка, заготовки закончились в контейнере 1
q7 - лампочка, контейнер 4 для пропечатанных заготовок полон
q8 - лампочка аварийного состояния

Система: Контейнер 1
                    Лента 1
                           Контейнер 2
                                      Лента 2
                                             Контейнер 3
                                                        Лента 3
                                                               Контейнер 4

Система работает следующим образом:
1.  Оператор нажимает кнопку старта. Запускается лента 1.

2.  а) Контейнер 1 с заготовками не пустой. Контейнер 2 и 3 с заготовками пустой. Открывается низ контейнер 1.
    б) Контейнер 1 и 2 с заготовками не пустой. Контейнер 3 с заготовками пустой. Открывается низ контейнер 1 и 2. 
    в) Контейнер 1 и 2 и 3 с заготовками пустой. Вызов сигнала и остановка ленты 1 и 2 и 3.
    г) Контейнер 2 и 3 с заготовками не пустой. Контейнер 1 с заготовками пустой. Вызов сигнала и остановка ленты 1. Открывается низ контейнер 2 и 3.
    д) Контейнер 2 с заготовками не пустой. Контейнер 1 и 3 с заготовками пустой. Вызов сигнала и остановка ленты 1 и 3. Открывается низ контейнер 2.
    е) Контейнер 3 с заготовками не пустой. Контейнер 1 и 2 с заготовками пустой. Вызов сигнала и остановка ленты 1 и 2. Открывается низ контейнер 3.
    ё) Контейнер 1 и 2 и 3 с заготовками не пустой. Открывается низ контейнер 1 и 2 и 3.

 3. а) Заготовка едет по ленте 1, но еще не достигла датчика печати 1. 9
    б) Заготовка едет по ленте 1 и 2, но еще не достигла датчика печати 1 и 2.
    в) Заготовка едет по ленте 2, но еще не достигла датчика печати 2.
    г) Заготовка едет по ленте 1 и 2 и 3, но еще не достигла датчика печати 1 и 2 и 3.
    д) Заготовка едет по ленте 2 и 3, но еще не достигла датчика печати 2 и 3.
    е) Заготовка едет по ленте 3, но еще не достигла датчика печати 3.

 4. а) Заготовка достигла датчика печати 1. Печать 1 опускается. 15
    б) Заготовка достигла датчика печати 1 и 2. Печать 1 и 2 опускается.
    в) Заготовка достигла датчика печати 2. Печать 2 опускается.
    г) Заготовка достигла датчика печати 1 и 2 и 3. Печать 1 и 2 и 3 опускается.
    д) Заготовка достигла датчика печати 2 и 3. Печать 2 и 3 опускается.
    е) Заготовка достигла датчика печати 3. Печать 3 опускается.

 5. а) Деталь продолжает движение по ленте 1. 21
    б) Деталь продолжает движение по ленте 1 и 2.
    в) Деталь продолжает движение по ленте 2.
    г) Деталь продолжает движение по ленте 1 и 2 и 3.
    д) Деталь продолжает движение по ленте 2 и 3.
    е) Деталь продолжает движение по ленте 3.

 6. а) Деталь достигла конца ленты 1. Открывается верх контейнера 2. Запускается лента 2. 27
    б) Деталь достигла конца ленты 2. Открывается верх контейнера 3. Запускается лента 3.
    в) Деталь достигла конца ленты 1 и 2. Открывается верх контейнера 2 и 3. Запускается лента 3.
    г) Деталь достигла конца ленты 3. Открывается верх контейнера 4.
    д) Деталь достигла конца ленты 2 и 3. Открывается верх контейнера 3 и 4.
    е) Деталь достигла конца ленты 1 и 2 и 3. Открывается верх контейнера 2 и 3 и 4.

7.  а) Контейнер 4 стал заполнен. Останавливаем процесс. 33
    б) Контейнер 4 не заполнен. Если деталь двигалась по ленте 1, то привод работает дальше и 2. Продолжаем процесс в шаг 2.
    в) Контейнер 4 не заполнен. Если деталь двигалась по ленте 1 и 2, то привод работает дальше и 3. Продолжаем процесс в шаг 2.
    г) Контейнер 4 не заполнен. Если деталь двигалась по ленте 2, то привод работает дальше и 3. Продолжаем процесс в шаг 2.
    д) Контейнер 4 не заполнен. Если деталь двигалась по ленте 1 и 2 и 3, то привод работает дальше. Продолжаем процесс в шаг 2.
    е) Контейнер 4 не заполнен. Если деталь двигалась по ленте 2 и 3, то привод работает дальше. Продолжаем процесс в шаг 2.
    ё) Контейнер 4 не заполнен. Если деталь двигалась по ленте 3, то привод работает дальше. Продолжаем процесс в шаг 2.

8.  В любой момент, когда нажата кнопка остановки, процесс должен быть остановлен. 40

9.  При переходе в неизвестные состояния процесс должен быть остановлен. 41

                ВХОДНЫЕ ЗНАЧЕНИЯ                                  ||                          ВЫХОДНЫЕ ЗНАЧЕНИЯ
Шаг | i01| i02| i03| i11| i12| i13| i24| i31| i32| i33|  i4 |  i5 || q01| q02| q03| q11| q12| q13| q22| q23| q24| q31| q32 | q33 |  q6 |  q7 |  q8 |
____________________________________________________________________________________________________________________________________________________
1   |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   1 |   0 ||  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
____________________________________________________________________________________________________________________________________________________
2а  |  0 |  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
2б  |  0 |  0 |  0 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  0 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
2в  |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   1 |   0 |   1 |
2г  |  0 |  0 |  0 |  0 |  1 |  1 |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  1 |  1 |  0 |  1 |  1 |  0 |  0 |  0 |  0 |   0 |   0 |   1 |   0 |   0 |
2д  |  0 |  0 |  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  1 |  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   1 |   0 |   0 |
2е  |  0 |  0 |  0 |  0 |  0 |  1 |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  0 |  1 |  0 |  0 |  1 |  0 |  0 |  0 |  0 |   0 |   0 |   1 |   0 |   0 |
2ё  |  0 |  0 |  0 |  1 |  1 |  1 |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  1 |  1 |  1 |  1 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
____________________________________________________________________________________________________________________________________________________
3а  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
3б  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
3в  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
3г  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
3д  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
3е  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
____________________________________________________________________________________________________________________________________________________
4а  |  0 |  0 |  0 |  X |  X |  X |  0 |  1 |  0 |  0 |   0 |   0 ||  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  1 |   0 |   0 |   0 |   0 |   0 |
4б  |  0 |  0 |  0 |  X |  X |  X |  0 |  1 |  1 |  0 |   0 |   0 ||  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  1 |   1 |   0 |   0 |   0 |   0 |
4в  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  1 |  0 |   0 |   0 ||  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   1 |   0 |   0 |   0 |   0 |
4г  |  0 |  0 |  0 |  X |  X |  X |  0 |  1 |  1 |  1 |   0 |   0 ||  1 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  1 |   1 |   1 |   0 |   0 |   0 |
4д  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  1 |  1 |   0 |   0 ||  0 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   1 |   1 |   0 |   0 |   0 |
4е  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  1 |   0 |   0 ||  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   1 |   0 |   0 |   0 |
____________________________________________________________________________________________________________________________________________________
5а  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
5б  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
5в  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
5г  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
5д  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
5е  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
____________________________________________________________________________________________________________________________________________________
6а  |  1 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  0 |  0 |  0 |  0 |  1 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
6б  |  0 |  1 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  1 |  1 |  0 |  0 |  0 |  0 |  1 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
6в  |  1 |  1 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  1 |  0 |  0 |  0 |  1 |  1 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
6г  |  0 |  0 |  1 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |  1 |  0 |   0 |   0 |   0 |   0 |   0 |
6д  |  0 |  1 |  1 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  1 |  1 |  0 |  0 |  0 |  0 |  1 |  1 |  0 |   0 |   0 |   0 |   0 |   0 |
6е  |  1 |  1 |  1 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  1 |  0 |  0 |  0 |  1 |  1 |  1 |  0 |   0 |   0 |   0 |   0 |   0 |
____________________________________________________________________________________________________________________________________________________
7а  |  0 |  0 |  0 |  X |  X |  X |  1 |  0 |  0 |  0 |   0 |   0 ||  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   1 |   1 |
7б  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
7в  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
7г  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
7д  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
7е  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
7ё  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
____________________________________________________________________________________________________________________________________________________
8   |  X |  X |  X |  X |  X |  X |  X |  X |  X |  X |   X |   1 ||  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
____________________________________________________________________________________________________________________________________________________
9   |  ? |  ? |  ? |  ? |  ? |  ? |  ? |  ? |  ? |  ? |   ? |   ? ||  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   1 |
*/