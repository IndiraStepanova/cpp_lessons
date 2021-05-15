/*
Реализуйте функцию swap_min, которая принимает на вход двумерный массив целых чисел, ищет в этом массиве строку, 
содержащую наименьшее среди всех элементов массива значение, и меняет эту строку местами с первой строкой массива.

Подумайте, как обменять строки массива, не обменивая элементы строк по-отдельности.

Требования к реализации: при выполнении этого задания вы можете определять любые вспомогательные функции. Вводить или 
выводить что-либо не нужно. Реализовывать функцию main не нужно.
*/

#include <iostream>
#include <string>
#include <limits>
using namespace std;

int **create_array(unsigned rows, unsigned cols)
{
    int **m = new int *[rows];
    for (unsigned i = 0; i < rows; ++i)
    {
        m[i] = new int[cols];
    }
    return m;
}

int row_with_min_value(int *m[], unsigned rows, unsigned cols)
{
    int num_min = numeric_limits<int>::max();
    unsigned min_row = 0;
    for (unsigned row = 0; row < rows; ++row)
    {
        for (unsigned col = 0; col < cols; ++col)
        {
            if (num_min > m[row][col])
            {
                num_min = m[row][col];
                min_row = row;
            }
        }
    }
    return min_row;
}

void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int min_row = row_with_min_value(m, rows, cols);
    int *temp = m[0];
    m[0] = m[min_row];
    m[min_row] = temp;
}

int main()
{
    unsigned row = 4;
    unsigned col = 5;
    int value = 1;
    unsigned min_row = 0;

    int **my_array = create_array(row, col);

    for (unsigned i = 0; i < row; ++i)
    {
        for (unsigned j = 0; j < col; ++j)
        {
            my_array[i][j] = value;
            cout << my_array[i][j] << '\t';
            value++;
        }
        cout << endl;
    }
    cout << endl;

    swap_min(my_array, row, col);

    for (unsigned i = 0; i < row; ++i)
    {
        for (unsigned j = 0; j < col; ++j)
        {
            cout << my_array[i][j] << '\t';
        }
        cout << endl;
    }

    return 0;
}