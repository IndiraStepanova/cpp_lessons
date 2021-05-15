/*Дан прямоугольный массив размером n×m. Поверните его на 90 градусов по часовой стрелке, записав результат в новый массив размером m×n.

Формат входных данных
Вводятся два числа n и m, не превосходящие 100, затем массив размером n×m.

Формат выходных данных
Выведите получившийся массив. Числа при выводе разделяйте одним пробелом.*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
  int n = 0, m = 0;
  cin >> n >> m;

  vector<vector<int>> a(n, vector<int>(m));

  for (int row = 0; row < n; row++)
  {
    for (int col = 0; col < m; col++)
    {
      cin >> a[row][col];
    }
  }

  for (int row = 0; row < m; row++)
  {
    for (int col = n- 1; col >= 0; col--)
    {
      cout << a[col][row] << ' ';
    } cout << endl;
  }



 
  return 0;
}
