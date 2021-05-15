//отсортировать по среднему баллу; вывести фамилию и имя

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct pupil
{
    string surname;
    string name;
    int math;
    int phisics;
    int informathics;
};

bool cmp(pupil a, pupil b)
{
    return ((a.math + a.phisics + a.informathics) / 3) > ((b.math + b.phisics + b.informathics) / 3);
    
}

int main()
{
    int n;
    cin >> n;

    vector<pupil> a(n);
    for (int i = 0; i < n; i++)
    {
        string surname;
        string name;
        int math;
        int phisics;
        int informathics;
        cin >> surname >> name >> math >> phisics >> informathics;
        pupil struct_temp;
        struct_temp.surname = surname;
        struct_temp.name = name;
        struct_temp.math = math;
        struct_temp.phisics = phisics;
        struct_temp.informathics = informathics;
        
        a[i] = struct_temp;
    }
    sort(a.begin(), a.end(), cmp);
    for (auto now : a)
    {
        cout << now.surname << " " << now.name << endl;
    } 

    return 0;
}