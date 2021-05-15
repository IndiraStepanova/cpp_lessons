/*Напишите функцию, которая принимает на вход целочисленную матрицу M (другими словами, просто двумерный целочисленный 
массив) размера rows × cols, и возвращает транспонированную матрицу M^T (тоже двумерный целочисленный массив) 
размера cols × rows. Если в M на пересечении ii-ой строки и   jj-ого столбца стояло число x, то на пересечении  
jj-ой строки и ii-ого столбца в матрице M^T тоже будет стоять число x, или другими словами M^T[j][i] = M[i][j]

Обратите внимание, что вам неизвестно, каким именно способом выделялась память для массива M. Выделять память под 
массив M^T можете любым удобным вам способом. Изменять исходную матрицу нельзя.

Требования к реализации: при выполнении этого задания вы можете определять любые вспомогательные функции. Вводить или 
выводить что-либо не нужно. Реализовывать функцию main не нужно.
*/

#include <iostream>
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

/*void free_array(int **m, unsigned a, unsigned b)
{
    delete[] m[0];
    delete[] m;
}*/

int **transpose(const int *const *m, unsigned rows, unsigned cols)
{
    int **trans_m = create_array(cols, rows);
    for (unsigned i = 0; i < cols; ++i)
    {
        for (unsigned j = 0; j < rows; ++j)
        {
            trans_m[i][j] = m[j][i];
        }
    }
    return trans_m;
}

int main()
{
    unsigned row = 4;
    unsigned col = 5;
    int value = 1;

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

    int **transpose_array = transpose(my_array, row, col);

    for (unsigned i = 0; i < col; ++i)
    {
        for (unsigned j = 0; j < row; ++j)
        {
            cout << transpose_array[i][j] << '\t';
        }
        cout << endl;
    }

    return 0;
}