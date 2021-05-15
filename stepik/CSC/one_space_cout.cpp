//убираем лишние пробелы

#include <iostream>
using namespace std;

int main()
{
    char c = '\0';
    char previous;


    while (cin.get(c))
    {
        if ((c != ' ') || (previous != ' '))
        {
            cout << c;
            previous = c;
        }
    }

    return 0;
}