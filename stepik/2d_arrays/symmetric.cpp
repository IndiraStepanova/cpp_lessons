/*Дано число n, не превосходящее 10, и массив размером n × n. Проверьте, является ли этот массив симметричным относительно главной 
диагонали. Выведите слово “YES”, если массив симметричный, и слово “NO” в противном случае.*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
  int n = 0;
  cin >> n;

  bool result = true;
  vector<vector<int>> a(n, vector<int>(n));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
  }
  // вычисления

  for (int row = 0; row < n; row++)
  {
    for (int col = row + 1; col < n; col++)
    {

      if (a[row][col] != a[col][row])
      {
        result = false;
      }
      if (result == false)
        break;
    }
    if (result == false)
      break;
  }

  //вывод
  if (result == true)
  {
    cout << "YES";
  }
  else
  {
    cout << "NO";
  }

  return 0;
}
