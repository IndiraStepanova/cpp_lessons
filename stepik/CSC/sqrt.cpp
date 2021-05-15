//решаем квадратное уравнение

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

double discriminant(int a, int b, int c)
{
    return b * b - 4 * a * c;
}

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    double x_1 = 0;
    double x_2 = 0;
    cin >> a >> b >> c;
    double D = discriminant(a, b, c);
    if (D < 0)
        cout << "No real roots";
    else if (D == 0)
    {
        x_1 = -b / (2 * a);
        cout << x_1 << " " << x_1;
    }
    else
    {
        x_1 = (-b - sqrt(D)) / (2 * a);
        x_2 = (-b + sqrt(D)) / (2 * a);
        cout << x_1 << ' ' << x_2;
    }
    return 0;
}
