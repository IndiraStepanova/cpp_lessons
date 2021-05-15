/*Выведите все исходные точки в порядке возрастания их расстояний от начала координат. 

Входные данные: 
Программа получает на вход набор точек на плоскости. Сначала задано количество точек n, затем идет последовательность 
из n строк, каждая из которых содержит два числа: координаты точки. Величина n не превосходит 100, все исходные координаты 
– целые числа, не превосходящие 103.

Выходные данные: 
Необходимо вывести все исходные точки в порядке возрастания их расстояний от начала координат.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct coordinates {
    int x;
    int y;
};

bool cmp(coordinates a, coordinates b) 
{
   return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
}

int main() {
    int n;
    cin >> n;
    vector <coordinates> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        int y;
        cin >> x >> y;
        coordinates struct_temp; // временная структура
        struct_temp.x = x;
        struct_temp.y = y;
        a[i] = struct_temp; // создание пары значение - номер
    }
    sort(a.begin(), a.end(), cmp);
    for (auto now : a) {
        cout << now.x << " " << now.y << endl;
    }
    return 0;
}