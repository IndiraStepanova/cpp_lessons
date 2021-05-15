/*Реализованные в предыдущих заданиях конструкторы и деструктор берут на себя работу по управлению ресурсами. Теперь можно дополнить 
структуру String различными полезными методами.

Для работы со строками можно придумать множество полезных методов (подумайте, какие методы пригодились бы вам, и чего вам не хватает 
для их реализации). Примером такого метода может послужить метод append — он добавляет копию строки-аргумента в конец текущей строки (т.е. 
в конец строки, у которой он был вызван).

String s1("Hello,");
String s2(" world!");

s1.append(s2); // теперь s1 хранит "Hello, world!"
Ваша задача реализовать метод append.

При выполнении задания будьте аккуратны при работе с памятью — при вызове метода не должно возникать утечек памяти. Кроме того, не забудьте, 
что size хранит размер без учета завершающего 0 символа.

Требования к реализации: при реализации вы можете заводить любые вспомогательные функции и методы. В шаблоне вы увидите объявления уже 
известных вам конструкторов и деструкторов, реализовывать их заново не нужно, они уже реализованы. Вводить или выводить что-либо не нужно. Реализовывать main не нужно. Для работы с памятью не используйте функции из cstdlib (malloc, realloc, calloc и free).

Кроме того, ваша реализация должна корректно работать в следующем тесте:

String s("Hello");
s.append(s); // теперь s хранит "HelloHello"*/

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
        delete [] str;
    }
    /* Реализуйте этот метод. */
    void append(String &other)
    {
        char * new_str = new char [size + other.size + 1];
        strcpy(new_str, str);
        strncat(new_str, other.str, other.size);

        delete [] str;

        str = new_str;
        size = size + other.size;     

    }

    size_t size;
    char *str;
};


struct SomeClass{
    int value1;
    int value2;

    SomeClass(){
        value1 = 0;
        value2 = 0;
        cout << "default" << endl;
    }

    SomeClass(int value1, int value2){
        this->value1 = value1;
        this->value2 = value2;
        cout << "non default" << endl;
    }

    SomeClass(int value){
        value1 = value;
        value2 = value;
        cout << "non default2" << endl;
    }

};

int main()
{


    String name("Indira");
    String secondName("Stepanova");

    name.append(name);

    cout << name.str << endl; //IndiraStepanova

   

    return 0;
}