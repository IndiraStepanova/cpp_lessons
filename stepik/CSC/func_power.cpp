//функция возведения в степень

#include <vector>
#include <iostream>
using namespace std;

int power(int x, unsigned p) {
    int answer = 1;
    for (int i = 0; i < p; i++) {
        answer = answer * x; 
    }
    return answer;
}

int main()
{
    int x = 0, y = 0;
    unsigned p;
    cin >> x >> p;
    y = power(x, p);
    cout << y;

    return 0;
}