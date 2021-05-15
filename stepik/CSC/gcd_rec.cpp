//задание: найти наибольший общий делитель рекурсивным способом

#include <iostream>
using namespace std;


unsigned gcd(unsigned a, unsigned b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}


int main() {
    int a = 0;
    int b = 0;
    cin >> a >> b;
    cout << gcd(a, b);

    return 0;
}