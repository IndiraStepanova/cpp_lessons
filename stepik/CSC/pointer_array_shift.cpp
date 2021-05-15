#include <iostream>
using namespace std;

void reverse(int *l, int *r)
{
    int temp = 0;
    while (l < r)
    {
        //меняем местами значения, на которые указывают указатели
        temp = *l;
        *l = *r;
        *r = temp;
        //сдвигаем указатели вправо и влево соответственно
        l++;
        r--;
    }
}

void rotate(int a[], unsigned size, int shift)
{
    int real_shift = shift % size;
    int *p = &a[0]; // адрес начала массива
    int *q = &a[size - 1]; //адрес последнего элемента массива (передаем по индексу (size -1))
    
    // разворачиваем весь массив
    reverse(p, q); 
   
    //разворачиваем левую часть от начала массива до size - shift - 1, т.к сдвиг совершется влево
    reverse(p, (p + size - real_shift - 1)); 
    
    //разворачиваем правую часть от size - shift - 1 до последнего элемента
    reverse((p + size - real_shift), q); //     
}



int main()
{
    const unsigned size = 5;

    int shift = 7;

    int a[size];
    for (int i = 0; i < size; i++)
    {
        a[i] = i;
    }

    rotate(&a[0], size, shift);

    for (int i = 0; i < size; i++)
        cout << a[i];

    return 0;
}