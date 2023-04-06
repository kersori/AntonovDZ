#include "rational.h"

using namespace std;

int main()
{
	int n;
	int a, b;
	bool check1 = true;
	bool check2 = true;
	int drob1, drob2;
	int f1, f2, f3, f4;
	int func_num;
	rational tmp;
	rational tmp2(0, 0);
	rational tmp3(0, 0);

	setlocale(LC_ALL, "Russian");

	while (true)
	{
		cout << "������� ���������� ������ (�� ����� 2):  " << endl << "-> ";
		cin >> n;
		if (n < 2)
		{
			continue;
		}
		else
		{
			break;
		}
	}

	rational* mass = new rational[n];

	for (int i = 0; i < n; i++)
	{
		cout << "������� ��������� � ����������� ����� �" << i + 1 << " ����� ������: " << endl << "-> ";
		cin >> a >> b;
		mass[i].set(a, b);
	}

	for (int i = 0; i < n; i++)
	{
		mass[i].show(i);
	}

	while (check1 == true)
	{
		cout << endl << "�������� ����� ��� ������ �������� (����� ������) -> �� 1 �� " << n << " ��� ������ �� ��������� ������� ���� ������ ����� �� ������-> 0." << endl << "-> ";
		cin >> drob1 >> drob2;

		if ((drob1 - 1 < 0) || (drob2 - 1 < 0))
		{
			break;
		}

		if ((drob1 - 1 > n - 1) || (drob2 - 1 > n - 1))
		{
			cout << "����� ��� ����� ������� �� ����������" << endl;
			continue;
		}

		cout << endl << "�� ������� ����� �" << drob1 << " � �" << drob2 << endl;
		check2 = true;
		while (check2 == true)
		{
			cout << endl <<
				"�������� ��������" << endl <<
				"0 - ����� �� ���������" << endl <<
				"1 - �������� ������" << endl <<
				"2 - ������� ������" << endl <<
				"3 - ���������� ��������� �� �������" << endl <<
				"4 - ��������� ������ (==)" << endl <<
				"5 - ��������� ������ (>)" << endl <<
				"6 - ������������ ������ (=)" << endl <<
				"7 - ������� � ����� ������ ������" << endl <<
				"-> ";
			cin >> func_num;

			if (func_num == 0)
			{
				check2 = false;
				check1 = false;
				break;
			}

			switch (func_num)
			{
			case 1:
				tmp = (mass[drob1 - 1] + mass[drob2 - 1]);
				cout << "����� ������ ����� (+): " << tmp.out1() << "/" << tmp.out2() << endl;
				break;

			case 2:
				tmp = (mass[drob1 - 1] - mass[drob2 - 1]);
				cout << "������� ������ ����� (-): " << tmp.out1() << "/" << tmp.out2() << endl;
				break;

			case 3:
				tmp = mass[drob1 - 1]++;
				cout << "���������� ��������� �� ������� (++): " << tmp.out1() << "/" << tmp.out2() << endl;
				tmp = mass[drob2 - 1]++;
				cout << "���������� ��������� �� ������� (++): " << tmp.out1() << "/" << tmp.out2() << endl;
				break;

			case 4:
				cout << "��������� ������ (==): " << endl;
				if (mass[drob1 - 1] == mass[drob2 - 1])
				{
					cout << "����� �����" << endl;
				}
				else
				{
					cout << "����� �� �����" << endl;
				}
				break;

			case 5:
				cout << "��������� ������ (>): " << endl;
				if (mass[drob1 - 1] > mass[drob2 - 1])
				{
					cout << "����� 1 > ����� 2" << endl;
				}
				else
				{
					cout << "����� 1 < ����� 2" << endl;
				}
				break;

			case 6:
				cout << "���������� ����� (=). ������� ����� ��������� � ������������ ��� ���� ������ (����� ������. ������: 1 2 3 4)" << endl << "->";
				cin >> f1 >> f2 >> f3 >> f4;
				tmp2.set(f1, f2);
				tmp3.set(f3, f4);
				mass[drob1 - 1].operator=(tmp2);
				cout << "��������� ����� 1: " << mass[drob1 - 1].out1() << "/" << mass[drob1 - 1].out2() << endl;
				mass[drob2 - 1].operator=(tmp3);
				cout << "��������� ����� 2: " << mass[drob2 - 1].out1() << "/" << mass[drob2 - 1].out2() << endl;
				break;

			case 7:
				check2 = false;
				break;

			default:
				cout << "������";
				break;
			}

			cout << endl;
		}
	}

	delete[] mass;
}

