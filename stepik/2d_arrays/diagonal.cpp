/*По данным числам n и m заполните двумерный массив размером n×m числами от 1 до n×m “диагоналями”, как показано в примере.
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
    for (int d = 0; d < n + m - 1; d++)
    {
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (row == d - col)
                {
                    a[row][col] = cnt;
                    cnt++;
                }
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
