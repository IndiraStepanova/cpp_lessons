#include <iostream>
#include <string>

using namespace std;

void strcat(char *to, const char *from)
{
    int cnt = 0;
    while (*to != '\0')
    {
        to++;
    }
    while (*from != '\0')
    {
        *to = *from;
        from++;
        to++;
    }
    *to = '0';
}

int main()
{
    char s[11] = "bebebe";
    string s1 = "gggg";
    strcat(s, s1.c_str());
    cout << s;
    return 0;
}
