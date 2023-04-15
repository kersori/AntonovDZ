#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class Atype> class array
{
	Atype *a;
	int len;
public:
	array(int size);
	~array()
	{
		delete[]a;
	}

	Atype &operator[](int n);
	void Sort(void);
	void Sort(string str);
	void Out(void);
};

template <class Atype> array <Atype>::array(int size)
{
	len = size;
	a = new Atype[size];
}

template <class Atype> Atype &array <Atype>::operator[](int n)
{
	if(n < 0 || n > len - 1)
	{
		cout << "Выход за границу массива" << endl;
		exit(1);
	}
	return a[n];
}

template <class Atype> void array <Atype>::Sort(void)
{
	Atype b;
	for(int i = 0; i < len - 1; i++)
	{
		for(int j = 0; j < len - i - 1; j++)
		{
			if(a[j] > a[j + 1])
			{
				b = a[j];
				a[j] = a[j + 1];
				a[j + 1] = b;
			}
		}
	}
}

template <class Atype> void array <Atype>::Sort(string str)
{	
	vector<Atype> s;
	for(int i = 0; i < 5; i++)
	{
		s.push_back(a[i]);
	}
	sort(s.begin(),s.end());
	for(int i = 0; i < 5; i++)
	{
		a[i] = s[i];
	}
}

template <class Atype> void array <Atype>::Out(void)
{	
	for(int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}