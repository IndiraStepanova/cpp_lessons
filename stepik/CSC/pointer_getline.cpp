/*
Реализуйте функцию getline, которая считывает поток ввода посимвольно, пока не достигнет конца потока или не встретит 
символ переноса строки ('\n'), и возвращает C-style строку с прочитанными символами.

Обратите внимание, что так как размер ввода заранее неизвестен, то вам нужно будет перевыделять память в процессе чтения, 
если в потоке ввода оказалось больше символов, чем вы ожидали.

Память, возвращенная из функции будет освобождена оператором delete[]. Символ переноса строки ('\n') добавлять в строку не 
нужно, но не забудьте, что в конце C-style строки должен быть завершающий нулевой символ.

Требования к реализации: при выполнении данного задания вы можете определять любые вспомогательные функции, если они вам 
нужны. Определять функцию main не нужно.*/

#include <iostream>
using namespace std;

char *resize(const char *str, unsigned size, unsigned new_size)
{
    char *new_str;
    new_str = new char[new_size];
    for (int i = 0; i < size && i < new_size; i++)
    {
        new_str[i] = str[i];
    }
    delete[] str;

    return new_str;
}

char *getline()
{
    char c = '\0';
    char *my_array;
    int size_array = 1;
    int capacity = 1024;
    my_array = new char[capacity];
    

    for (int i = 0; cin.get(c) && c != '\n'; i++)
    {
        if (size_array == capacity)
        {
            my_array = resize(my_array, capacity, capacity * 2);
            capacity = capacity * 2;
        }
        
        my_array[i] = c;
        size_array++;
    }
    my_array[size_array - 1] = '\0';

    return my_array;
}

int main()
{
    getline();
    return 0;
}