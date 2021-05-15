/*Во время проведения олимпиады каждый из участников получил свой идентификационный номер – натуральное число. 
Необходимо отсортировать список участников олимпиады по количеству набранных ими баллов.

Входные данные:
На первой строке дано число N (1 ≤ N ≤ 1000) – количество участников. На каждой следующей строке даны идентификационный 
номер и набранное число баллов соответствующего участника. Все числа во входном файле не превышают 105.

Выходные данные: 
В выходной файл выведите исходный список в порядке убывания баллов. Если у некоторых участников одинаковые баллы, то 
их между собой нужно упорядочить в порядке возрастания идентификационного номера.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct man {
    int id;
    int mark;
};

bool cmp(man a, man b) {
    if (a.mark == b.mark)
    {
        return a.id < b.id;
    }

    return a.mark > b.mark;
}

int main() {
    int n;
    cin >> n;
    vector <man> a(n);
    for (int i = 0; i < n; i++) {
        int id;
        int mark;
        cin >> id >> mark;
        man struct_temp; // временная структура
        struct_temp.id = id;
        struct_temp.mark = mark;
        a[i] = struct_temp; // создание пары значение - номер
    }
    sort(a.begin(), a.end(), cmp);
    for (auto now : a) {
        cout << now.id << " " << now.mark << endl;
    }
    return 0;
}