/*Добавьте в класс String реализацию конструктора копирования. Инвариант класса остается тем же (в size хранится размер строки без 
завершающего 0 символа, str указывает на C-style строку, т. е. с завершающим нулевым символом).

Требования к реализации: вы можете заводить любые вспомогательные методы или функции, но не реализуйте заново методы из предыдущих заданий 
— они уже реализованы. При реализации не нужно вводить или выводить что-либо. Реализовывать main не нужно. Не используйте функции из cstdlib 
(malloc, calloc, realloc и free).*/

#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>
using namespace std;

struct String
{
    String(const char *str = "")
    {
        size = strlen(str);
        this->str = new char[size + 1];
        strcpy(this->str, str);
    }

    String(size_t n, char c)
    {
        size = n;
        this->str = new char[size + 1];
        for (int i = 0; i < n; ++i)
        {
            str[i] = c;
        }
        str[n] = '\0';
    }

    //и деструктор */
    ~String()
    {
        delete[] str;
    }

    /* Реализуйте конструктор копирования */
    String(const String &other)
    {
        size = other.size;
        str = new char[size + 1];
        {
            for (size_t i = 0; i != size; ++i)
            {
                str[i] = other.str[i];
            }
            str[size] = '\0';
        }
    }
    /*конструктор копирования_2*/
    /*
    String(const String &other):
    size(other.size), str(new char [size+1])
    {
        for (int i = 0; i < size+1; ++i)
        str[i] = other.str[i];
    }*/

    void append(String &other)
    {
        char *new_str = new char[size + other.size + 1];
        strcpy(new_str, str);
        strncat(new_str, other.str, other.size);

        delete[] str;

        str = new_str;
        size = size + other.size;
    }

    size_t size;
    char *str;
};

int main()
{

    String name("Indira");
    String secondName("Stepanova");

    name.append(name);

    cout << name.str << endl; //IndiraStepanova

    return 0;
}