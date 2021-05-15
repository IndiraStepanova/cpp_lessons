/*В кинотеатре n рядов по m мест в каждом (n и m не превосходят 20). В двумерном массиве хранится информация о проданных билетах, 
число 1 означает, что билет на данное место уже продан, число 0 означает, что место свободно. Поступил запрос на продажу k билетов 
на соседние места в одном ряду. Определите, можно ли выполнить такой запрос.

    Формат входных данных
Программа получает на вход числа n и m. Далее идет n строк, содержащих m чисел (0 или 1), разделенных пробелами. Затем дано число k.
    Формат выходных данных
Программа должна вывести номер ряда, в котором есть k подряд идущих свободных мест. Если таких рядов несколько, то выведите номер 
наименьшего подходящего ряда. Если подходящего ряда нет, выведите число 0.*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int rows = 0, columns = 0;
    cin >> rows >> columns;

    vector<vector<int>> a(rows, vector<int>(columns));

    //ввод

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            cin >> a[row][col];
        }
    }
    
    int cnt = 0;
    int k = 0;
    int row_for_order = 0;
    cin >> k;

    // вычисления
    for (int row = 0; row < rows; row++)
    {
        cnt = 0;
        for (int col = 0; col < columns; col++)
        {
            if (a[row][col] == 0)
            {
                cnt++;
            }
            else cnt = 0;
            if (cnt == k) 
            {
                row_for_order = row+1;
            } 
            if (cnt == k) break;
            
        } 
        if (cnt == k) break;
    }

    if (cnt == k)
    {
        cout << row_for_order;
    } else cout << 0;
    

    return 0;
}
