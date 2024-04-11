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

    int p1 = 0; // ������
    int p2 = 0;
    int p3 = 0;

    int n; // ���������� �������

    Conteiner conteiner1; // 4 ����������
    Conteiner conteiner2;
    Conteiner conteiner3; 
    Conteiner conteiner4;

    Lamp lamp1; // ����� ����������

    Datchik datchik1; // ������, ��������� ����� �� ���� ����� 1
    Datchik datchik2; // ������, ��������� ����� �� ���� ����� 2
    Datchik datchik3; // ������, ��������� ����� �� ���� ����� 3
    Datchik datchik4; // ������, ������� ��������� � ���������� 1
    Datchik datchik5; // ������, ������� ��������� � ���������� 2
    Datchik datchik6; // ������, ������� ��������� � ���������� 3
    Datchik datchik7; // ������, ���������� ���������� 4 � �������� ��������
    Datchik datchik8; // ������ ����������� ��������� � ������ 1
    Datchik datchik9; // ������ ����������� ��������� � ������ 2
    Datchik datchik10; // ������ ����������� ��������� � ������ 3

    Privod privod1; // ����������� �����, ������ 1
    Privod privod2; // ����������� �����, ������ 2
    Privod privod3; // ����������� �����, ������ 3
    Privod privod4; // �������� ���������� � �����������, ������ 1 ���
    Privod privod5; // �������� ���������� � �����������, ������ 2 ���
    Privod privod6; // �������� ���������� � �����������, ������ 3 ���
    Privod privod7; // �������� ���������� � �������������� �����������, ������ 2 ����
    Privod privod8; // �������� ���������� � �������������� �����������, ������ 3 ����
    Privod privod9; // �������� ���������� � �������������� �����������, ������ 4 ����
    Privod privod10; // ������ ������ 1
    Privod privod11; // ������ ������ 2
    Privod privod12; // ������ ������ 3
    
    ifstream fin1("vhod.txt");

    ofstream fout1("vihod.txt");

    string buff;

    int mass1[21]{ 1, 2, 9, 15, 21, 27, 34, 6, 11, 17, 23, 28, 36, 7, 14, 20, 26, 30, 33, 40, 41 };
    int mass2[27]{ 1, 2, 9, 15, 21, 27, 34, 3, 10, 16, 22, 29, 35, 5, 13, 19, 25, 31, 38, 7, 14, 20, 26, 30, 33, 40, 41 };
    int mass3[33]{ 1, 2, 9, 15, 21, 27, 34, 3, 10, 16, 22, 29, 35, 8, 12, 18, 24, 32, 37, 5, 13, 19, 25, 31, 38, 7, 14, 20, 26, 30, 33, 40, 41 };

    while (true)
    {   
        cout << "�������� ������� ������� ����� ��������� � ����������: (��� ������ �� ��������� ������� 0)" << endl;

        cin >> n;

        if (n == 0)
        {
            break;
        }

        conteiner1.Set_N(n);

        cout << endl;

        if (conteiner1.Get_N() == 1) // ------------------------------------ ���� ������
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

                fin1.close(); // ��������� ����
                fout1.close(); // ��������� ����
            }

            cout << endl;
        }

        else if (conteiner1.Get_N() == 2) // ------------------------------------ ��� ������
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

                fin1.close(); // ��������� ����
                fout1.close(); // ��������� ����
            }

            cout << endl;
        }

        //int mass3[33]{ 1, 2, 9, 15, 21, 27, 34, 3, 10, 16, 22, 29, 35, 8, 12, 18, 24, 32, 37, 5, 13, 19, 25, 31, 38, 7, 14, 20, 26, 30, 33, 40, 41 };
        else if (conteiner1.Get_N() >= 3)  // ------------------------------------ ��� � ����� ������
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

                    fin1.close(); // ��������� ����
                    fout1.close(); // ��������� ����
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

                fin1.close(); // ��������� ����
                fout1.close(); // ��������� ����
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

                fin1.close(); // ��������� ����
                fout1.close(); // ��������� ����
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

                fin1.close(); // ��������� ����
                fout1.close(); // ��������� ����
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

                fin1.close(); // ��������� ����
                fout1.close(); // ��������� ����
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

                fin1.close(); // ��������� ����
                fout1.close(); // ��������� ����
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

                fin1.close(); // ��������� ����
                fout1.close(); // ��������� ����
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

                fin1.close(); // ��������� ����
                fout1.close(); // ��������� ����
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

                fin1.close(); // ��������� ����
                fout1.close(); // ��������� ����
            }

        }

        cout << endl;
        }

        else
        {
            cout << "�������� ����" << endl << endl;
        }
    }
}
/*-----------� ������ ������ ���������----------
I0 - ������, ��������� ����� �� ���� �����
I1 - ������, ������� ��������� � ����������
I2 - ������, ���������� ���������� � �������� ��������
I3 - ������ ����������� ��������� � ������
I4 - ������ ������
I5 - ������ ���������� ���������

Q0 - ����������� �����, ������
Q1 - �������� ���������� � ����������� ���
Q2 - �������� ���������� � �������������� ����������� ����
Q3 - ������ ������
Q6 - ��������, ��������� �����������
Q7 - ��������, ��������� ��� ������������ ��������� �����
Q8 - �������� ���������� ���������

-------------� ������ 3 ����������--------------
i01 - ������, ��������� ����� �� ���� ����� 1
i02 - ������, ��������� ����� �� ���� ����� 2
i03 - ������, ��������� ����� �� ���� ����� 3

i11 - ������, ������� ��������� � ���������� 1
i12 - ������, ������� ��������� � ���������� 2
i13 - ������, ������� ��������� � ���������� 3

i24 - ������, ���������� ���������� 4 � �������� ��������

i31 - ������ ����������� ��������� � ������ 1
i32 - ������ ����������� ��������� � ������ 2
i33 - ������ ����������� ��������� � ������ 3

i4 - ������ ������
i5 - ������ ���������� ���������

q01 - ����������� �����, ������ 1
q02 - ����������� �����, ������ 2
q03 - ����������� �����, ������ 3

q11 - �������� ���������� � �����������, ������ 1 ���
q12 - �������� ���������� � �����������, ������ 2 ���
q13 - �������� ���������� � �����������, ������ 3 ���

q22 - �������� ���������� � �������������� �����������, ������ 2 ����
q23 - �������� ���������� � �������������� �����������, ������ 3 ����
q24 - �������� ���������� � �������������� �����������, ������ 4 ����

q31 - ������ ������ 1
q32 - ������ ������ 2
q33 - ������ ������ 3

q6 - ��������, ��������� ����������� � ���������� 1
q7 - ��������, ��������� 4 ��� ������������� ��������� �����
q8 - �������� ���������� ���������

�������: ��������� 1
                    ����� 1
                           ��������� 2
                                      ����� 2
                                             ��������� 3
                                                        ����� 3
                                                               ��������� 4

������� �������� ��������� �������:
1.  �������� �������� ������ ������. ����������� ����� 1.

2.  �) ��������� 1 � ����������� �� ������. ��������� 2 � 3 � ����������� ������. ����������� ��� ��������� 1.
    �) ��������� 1 � 2 � ����������� �� ������. ��������� 3 � ����������� ������. ����������� ��� ��������� 1 � 2. 
    �) ��������� 1 � 2 � 3 � ����������� ������. ����� ������� � ��������� ����� 1 � 2 � 3.
    �) ��������� 2 � 3 � ����������� �� ������. ��������� 1 � ����������� ������. ����� ������� � ��������� ����� 1. ����������� ��� ��������� 2 � 3.
    �) ��������� 2 � ����������� �� ������. ��������� 1 � 3 � ����������� ������. ����� ������� � ��������� ����� 1 � 3. ����������� ��� ��������� 2.
    �) ��������� 3 � ����������� �� ������. ��������� 1 � 2 � ����������� ������. ����� ������� � ��������� ����� 1 � 2. ����������� ��� ��������� 3.
    �) ��������� 1 � 2 � 3 � ����������� �� ������. ����������� ��� ��������� 1 � 2 � 3.

 3. �) ��������� ���� �� ����� 1, �� ��� �� �������� ������� ������ 1. 9
    �) ��������� ���� �� ����� 1 � 2, �� ��� �� �������� ������� ������ 1 � 2.
    �) ��������� ���� �� ����� 2, �� ��� �� �������� ������� ������ 2.
    �) ��������� ���� �� ����� 1 � 2 � 3, �� ��� �� �������� ������� ������ 1 � 2 � 3.
    �) ��������� ���� �� ����� 2 � 3, �� ��� �� �������� ������� ������ 2 � 3.
    �) ��������� ���� �� ����� 3, �� ��� �� �������� ������� ������ 3.

 4. �) ��������� �������� ������� ������ 1. ������ 1 ����������. 15
    �) ��������� �������� ������� ������ 1 � 2. ������ 1 � 2 ����������.
    �) ��������� �������� ������� ������ 2. ������ 2 ����������.
    �) ��������� �������� ������� ������ 1 � 2 � 3. ������ 1 � 2 � 3 ����������.
    �) ��������� �������� ������� ������ 2 � 3. ������ 2 � 3 ����������.
    �) ��������� �������� ������� ������ 3. ������ 3 ����������.

 5. �) ������ ���������� �������� �� ����� 1. 21
    �) ������ ���������� �������� �� ����� 1 � 2.
    �) ������ ���������� �������� �� ����� 2.
    �) ������ ���������� �������� �� ����� 1 � 2 � 3.
    �) ������ ���������� �������� �� ����� 2 � 3.
    �) ������ ���������� �������� �� ����� 3.

 6. �) ������ �������� ����� ����� 1. ����������� ���� ���������� 2. ����������� ����� 2. 27
    �) ������ �������� ����� ����� 2. ����������� ���� ���������� 3. ����������� ����� 3.
    �) ������ �������� ����� ����� 1 � 2. ����������� ���� ���������� 2 � 3. ����������� ����� 3.
    �) ������ �������� ����� ����� 3. ����������� ���� ���������� 4.
    �) ������ �������� ����� ����� 2 � 3. ����������� ���� ���������� 3 � 4.
    �) ������ �������� ����� ����� 1 � 2 � 3. ����������� ���� ���������� 2 � 3 � 4.

7.  �) ��������� 4 ���� ��������. ������������� �������. 33
    �) ��������� 4 �� ��������. ���� ������ ��������� �� ����� 1, �� ������ �������� ������ � 2. ���������� ������� � ��� 2.
    �) ��������� 4 �� ��������. ���� ������ ��������� �� ����� 1 � 2, �� ������ �������� ������ � 3. ���������� ������� � ��� 2.
    �) ��������� 4 �� ��������. ���� ������ ��������� �� ����� 2, �� ������ �������� ������ � 3. ���������� ������� � ��� 2.
    �) ��������� 4 �� ��������. ���� ������ ��������� �� ����� 1 � 2 � 3, �� ������ �������� ������. ���������� ������� � ��� 2.
    �) ��������� 4 �� ��������. ���� ������ ��������� �� ����� 2 � 3, �� ������ �������� ������. ���������� ������� � ��� 2.
    �) ��������� 4 �� ��������. ���� ������ ��������� �� ����� 3, �� ������ �������� ������. ���������� ������� � ��� 2.

8.  � ����� ������, ����� ������ ������ ���������, ������� ������ ���� ����������. 40

9.  ��� �������� � ����������� ��������� ������� ������ ���� ����������. 41

                ������� ��������                                  ||                          �������� ��������
��� | i01| i02| i03| i11| i12| i13| i24| i31| i32| i33|  i4 |  i5 || q01| q02| q03| q11| q12| q13| q22| q23| q24| q31| q32 | q33 |  q6 |  q7 |  q8 |
____________________________________________________________________________________________________________________________________________________
1   |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   1 |   0 ||  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
____________________________________________________________________________________________________________________________________________________
2�  |  0 |  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
2�  |  0 |  0 |  0 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  0 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
2�  |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   1 |   0 |   1 |
2�  |  0 |  0 |  0 |  0 |  1 |  1 |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  1 |  1 |  0 |  1 |  1 |  0 |  0 |  0 |  0 |   0 |   0 |   1 |   0 |   0 |
2�  |  0 |  0 |  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  1 |  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   1 |   0 |   0 |
2�  |  0 |  0 |  0 |  0 |  0 |  1 |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  0 |  1 |  0 |  0 |  1 |  0 |  0 |  0 |  0 |   0 |   0 |   1 |   0 |   0 |
2�  |  0 |  0 |  0 |  1 |  1 |  1 |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  1 |  1 |  1 |  1 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
____________________________________________________________________________________________________________________________________________________
3�  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
3�  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
3�  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
3�  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
3�  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
3�  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
____________________________________________________________________________________________________________________________________________________
4�  |  0 |  0 |  0 |  X |  X |  X |  0 |  1 |  0 |  0 |   0 |   0 ||  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  1 |   0 |   0 |   0 |   0 |   0 |
4�  |  0 |  0 |  0 |  X |  X |  X |  0 |  1 |  1 |  0 |   0 |   0 ||  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  1 |   1 |   0 |   0 |   0 |   0 |
4�  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  1 |  0 |   0 |   0 ||  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   1 |   0 |   0 |   0 |   0 |
4�  |  0 |  0 |  0 |  X |  X |  X |  0 |  1 |  1 |  1 |   0 |   0 ||  1 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  1 |   1 |   1 |   0 |   0 |   0 |
4�  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  1 |  1 |   0 |   0 ||  0 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   1 |   1 |   0 |   0 |   0 |
4�  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  1 |   0 |   0 ||  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   1 |   0 |   0 |   0 |
____________________________________________________________________________________________________________________________________________________
5�  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
5�  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
5�  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
5�  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
5�  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
5�  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
____________________________________________________________________________________________________________________________________________________
6�  |  1 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  0 |  0 |  0 |  0 |  1 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
6�  |  0 |  1 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  1 |  1 |  0 |  0 |  0 |  0 |  1 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
6�  |  1 |  1 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  1 |  0 |  0 |  0 |  1 |  1 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
6�  |  0 |  0 |  1 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |  1 |  0 |   0 |   0 |   0 |   0 |   0 |
6�  |  0 |  1 |  1 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  1 |  1 |  0 |  0 |  0 |  0 |  1 |  1 |  0 |   0 |   0 |   0 |   0 |   0 |
6�  |  1 |  1 |  1 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  1 |  0 |  0 |  0 |  1 |  1 |  1 |  0 |   0 |   0 |   0 |   0 |   0 |
____________________________________________________________________________________________________________________________________________________
7�  |  0 |  0 |  0 |  X |  X |  X |  1 |  0 |  0 |  0 |   0 |   0 ||  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   1 |   1 |
7�  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
7�  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
7�  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
7�  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  1 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
7�  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
7�  |  0 |  0 |  0 |  X |  X |  X |  0 |  0 |  0 |  0 |   0 |   0 ||  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
____________________________________________________________________________________________________________________________________________________
8   |  X |  X |  X |  X |  X |  X |  X |  X |  X |  X |   X |   1 ||  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   0 |
____________________________________________________________________________________________________________________________________________________
9   |  ? |  ? |  ? |  ? |  ? |  ? |  ? |  ? |  ? |  ? |   ? |   ? ||  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |   0 |   0 |   0 |   0 |   1 |
*/