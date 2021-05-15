/*Когда вы пишите рекурсивный алгоритм с некой функцией f важно различать какие действия в теле функцией f целесообразно 
выполнять до рекурсивного вызова  дочерней функции, а какие после него! Например, на предидущем шаге была задача с двумя
 рекурсивными вызовами  foo((n * 2) / 3) + foo(n - 2); и видно что выполняются арифметические операции над аргументами 
 функции ПЕРЕД вызовом foo, а суммирование функций - после. Если же вы посмотрите на задачу с факториалом n * f(n-1) , 
 то здесь очевидно что аргумент функции уменьшается на еденицу ПЕРЕД вызовом f, а зато умножение на n выполняется уже 
 ПОСЛЕ возврата из f(n-1).  Если нарисовать цепочку рекурсивных вызовов функции факториала (обращенную вниз), то очевидно 
 что первый вид операций выполняется "на спуске" рекурсии, а второй - на "обратном ходе", т. е. подъёме (возврате вверх). 
 Не сложно заметить, что в случае с нашей задачей "переворота" последовательности чисел,  удобно выводить, уже считанные 
 по одному с потока ввода, числа на "обратном ходе" рекурсии, вед тогда все числа выведутся в обратном порядке естественным 
 образом! Ну конечно для этого нужно эти числа сначало как то считать и где то сохранить! Воспользуемся локальной переменой. Поскольку каждый вызов рекурсивной функции это отдельная копия в стеке то достаточно завести одну локальную переменную и считывать в неё одно число из поток ввода !  Если мы считаем число до вызова дочерней функции, оно будет доступно в нашей копии функии и после возврата из дочерней функции! Т.е. числа считываются по одному "на спуске" рекурсии, а выводятся по одному на "обратном ходе"!  Ещё один важный момент это правильно выставить условие прекращения рекурсии. В нашем случае, мы считываем по одному символу на вызов и делаем новый вызов пока не считаем число 0. В этом случае нет новых вызовов и начинается "обратный ход" рекурсии. Ну и наконец нужно определится с аргументами функции и возвращаемыми значениями функции. Возвращаемые значения удобно использовать тогда, когда мы вычисляем какое то конкретное значение функции как в случае с факториалом. Это не наш случай, поэтому можно использовать void.   Аргументы функции часто используют как параметер который сходится к какому то пограничному значению, которое используется как признак окончания рекурсии. Например, в случае с факториалом, аргумент n всё время уменьшается пока не достигнет значения 1 и тогда функция возвращает значение 1 и рекурсия начинает "обратный ход". В нашем случае, наше условие окончания рекурсии не зависит от каких либо параметров, 
а зависит от появления числа 0 на потоке ввода, поэтому наша функцию прекрасно обойдётся без параметров.

задание: рекурсивным способом вывести последовательность чисел, заканчивающихся 0, в обратной порядке*/


#include <iostream>
using namespace std;


void rec() 
{
    int n;
    cin >> n;
    if (n != 0)
    {
        rec();
        cout << n << ' ';
    }
    
}


int main() {
    rec();

    return 0;
}