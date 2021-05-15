/*Даны числа n и m. Заполните массив размером n × m в шахматном порядке: клетки одного цвета заполнены нулями, 
а другого цвета - заполнены числами натурального ряда сверху вниз, слева направо. В левом верхнем углу записано число 1.
Формат входных данных
Вводятся два числа n и m, не превышающие 100.

Формат выходных данных
Выведите полученный массив, отводя на вывод каждого элемента ровно 4 символа.*/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    //ввод размера матрицы

    int n = 0, m = 0, cnt = 1;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    //заполнение матрицы 

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
             if ((row + col) % 2 != 0) 
             {
                 a[row][col] = 0;
             } else 
             {
                a[row][col] = cnt;
                cnt++;
             }
             
        }
    }

    //вывод
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            cout << setw(4) << a[row][col];
        }
        cout << endl;
    }

    return 0;
}
