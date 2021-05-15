/*
Напишите функцию поиска первого вхождения шаблона в текст. В качестве первого параметра функция принимает текст (C-style 
строка), в которой нужно искать шаблон. 
В качестве второго параметра строку-шаблон (C-style строка), которую нужно найти. Функция возвращает позицию первого 
вхождения строки-шаблона, если он присутствует в строке (помните, что в C++ принято считать с 0), и -1, если шаблона в 
тексте нет.

Учтите, что пустой шаблон (строка длины 0) можно найти в любом месте текста.

Требования к реализации: при выполнении данного задания вы можете определять любые вспомогательные функции, если они вам 
нужны. Вводить или выводить что-либо не нужно. Реализовывать функцию main не нужно.*/
#include <iostream>
#include <string>
using namespace std;

bool starts_with(const char *text, const char *pattern)
{
    while (*text != '\0' || *pattern != '\0')
    {
        if (*text == *pattern)
        {
            ++text;
            ++pattern;
        }
        else if (*pattern == '\0')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int strstr(const char *text, const char *pattern)
{
    int index = 0;
    if (*pattern == '\0')
        return 0;

    for (; *text != '\0'; text++)
    {
        if (starts_with(text, pattern) == false)
        {
            ++index;
        }
        else
        {
            return index;
        }
    }
    return -1;
}

void RunStartsWithTest(const string &text, const string &pattern, bool expected)
{
    bool actual = starts_with(text.c_str(), pattern.c_str());
    if (actual != expected)
    {
        cout << "Failed! Text: " << text << ", pattern: " << pattern << ", expected: " << expected << endl;
    }
    else
    {
        cout << "Passed! Text: " << text << ", pattern: " << pattern << ", expected: " << expected << endl;
    }
}

void RunTests()
{
    RunStartsWithTest("indira", "ira", false);
    RunStartsWithTest("indira", "ind", true);
    RunStartsWithTest("indira", "indirastepanova", false);
    RunStartsWithTest("novaindira", "nova", true);
}

int main()
{

    RunTests();

    string text = "";
    string pattern = "";
    cout << strstr(text.c_str(), pattern.c_str());

    return 0;
}
