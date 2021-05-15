//логарифм по основанию 2

#include <iostream>
using namespace std;

int log(int a)
{
int answer = 1, p = 0;
    while(answer <= a)
    {
        answer *= 2; 
        p++;
    }
    return p - 1;
}

int main()
{
    int a = 0;
    int n = 0;
    cin >> n;
        
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        cout << log(a) << endl;
    }
    return 0;
}




