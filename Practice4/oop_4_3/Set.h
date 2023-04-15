#include <iostream>

using namespace std;

template <class Atype> class Set
{
    Atype* a; // Массив элементов множества.
    int len; // Количество элементов множества.

public:
    Set(int size) // Конструктор, выделяющий память под массив элементов.
    {
        len = size;

        a = new Atype[size];

        // Для нестандартных определить.
    }

    ~Set() // Деструктор, освобождающий выделенную память.
    {
        delete[]a;
    }

    bool In_Set(Atype T) // Функция, определяющая, является ли элемент членом множества.
    {
        for (int i = 0; i < len; i++)
        {
            if (a[i] == T)
            {
                return true;
            }
        }
        return false;
    }

    bool Add(Atype T) // Функция, добавляющая элемент в множество.
    {
        if (!In_Set(T))
        {
            Atype* tmp = new Atype[len + 1];
            for (int i = 0; i < len; i++)
            {
                tmp[i] = a[i];
            }
            tmp[len++] = T;
            delete[] a;
            a = tmp;
            return true;
        }
        return false;
    }

    bool Get(Atype T) // Функция, удаляющая элемент из множества.
    {
        if (In_Set(T))
        {
            Atype* tmp = new Atype[len - 1];
            int j = 0;
            for (int i = 0; i < len; i++)
            {
                if (a[i] != T)
                {
                    tmp[j++] = a[i];
                }
            }
            delete[]a;
            a = tmp;
            len--;
            return true;
        }
        return false;
    }

    bool Is_Full() // Функция, возвращающая количество элементов в множестве.
    {
        if (len > 0)
        {
            return true;
        }
        return false;
    }

    bool Is_Empty() // Функция, возвращающая количество элементов в множестве.
    {
        if(len == 0)
        {
            return true;
        }
        return false;
    }

    
    Set& operator+(Atype T) // Оператор + для добавления элементов в множество.
    {
        Add(T);
        return *this;
    }

    Atype& operator[](int n) // Оператор [].
    {
        if (n < 0 || n > len - 1)
        {
            cout << "Выход за границу массива";
            exit(1);
        }
        return a[n];
    }

    int Size() const // Функция, возвращающая количество элементов в множестве.
    {
        return len;
    }
};

class Point
{
    int x, y;
public:
    Point(int x1, int y1)
    {   
        this->x = x1;
        this->y = y1;
    }
    Point()
    {
        //this->x = 0;
        //this->y = 0;
    }

    friend ostream& operator<<(ostream& mass, Point& mass1)
    {
        mass << mass1.x << "," << mass1.y;
        return mass;
    }
    Point& operator=(Point& my_Point1)
    {
        this->x = my_Point1.x;
        this->y = my_Point1.y;
        return *this;
    }
    
    bool operator==(Point const& my_Point1)
    {
        return (this->x == my_Point1.x && my_Point1.y == this->y);
    }

    bool operator!=(Point const& my_Point1)
    {
        return (this->x != my_Point1.x || my_Point1.y != this->y);
    }
};