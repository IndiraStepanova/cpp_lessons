/*По данным числам n и m заполните двумерный массив размером n×m числами от 1 до n×m по спирали, выходящей из левого верхнего угла и 
закрученной по часовой стрелке, как показано в примере.
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

    int rows = 0, columns = 0, cnt = 1;
    cin >> rows >> columns;

    vector<vector<int>> a(rows, vector<int>(columns));

    //заполнение матрицы

    //вверх, слева направо
    int min_offset;
    if (rows < columns)
        min_offset = rows;
    else
        min_offset = columns;

    for (int offset = 0; offset < ((min_offset + 1) / 2); offset++)
    {
        for (int col = offset; col <= columns - 1 - offset; col++)
        {
            if (cnt <= rows * columns)
            {
                a[offset][col] = cnt;
                cnt++;
            }
        }
        //справа, сверху вниз
        for (int row = offset + 1; row <= rows - 1 - offset; row++)
        {
            if (cnt <= rows * columns)
            {
                a[row][columns - 1 - offset] = cnt;
                cnt++;
            }
        }
        //низ, справа налево
        for (int col = columns - 2 - offset; col >= offset; col--)
        {
            if (cnt <= rows * columns)
            {
                a[rows - 1 - offset][col] = cnt;
                cnt++;
            }
        }

        //слева. снизу вверх

        for (int row = rows - 2 - offset; row > offset; row--)
        {
            if (cnt <= rows * columns)
            {
                a[row][offset] = cnt;
                cnt++;
            }
        }
    }

    //вывод

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            cout << setw(4) << a[row][col];
        }
        cout << endl;
    }

    return 0;
}