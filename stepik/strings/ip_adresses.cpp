//проверяем валидность IP адреса

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//функция для проверки принадлежности символа типу число или "."
bool HasValidChars(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (!isdigit(s[i]) && !s[i] == '.')
        {
            return false;
        }
    }
    return true;
}

//функция для проверки длины строки
bool HasValidLength(string s)
{
    if (s.length() >= 7 && s.length() <= 14)
    {
        return true;
    }
    return false;
}

//функция для подсчета точек
int DotsCount(string s)
{
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '.')
        {
            cnt++;
        }
    }
    return cnt;
}
//функция, проверяющая, что всех точек в строке 3
bool HasThreeDots(string m)
{
    if (DotsCount(m) != 3)
    {
        return false;
    }
    return true;
}

/*bool Masks(string s)
{
    int first_dot = s.find(".");
    int second_dot = s.find(".", first_dot + 1);
    int third_dot = s.find(".", second_dot + 1);

    if (isdigit(s.substr(0, first_dot)) == true)
    int first_mask = stoi(s.substr(0, first_dot))
}*/

int main()
{

    string n;
    cin >> n;

    /* if (HasValidChars(n) == false)
    {
        cout << "NO";
        return 0;
    }

   if (HasValidLength(n) == false)
    {
        cout << "NO";
        return 0;
    }

    return 0;

    if (HasThreeDots(n) == false)
    {
        cout << "NO";
        return 0;
    } */

    

    return 0;
}
