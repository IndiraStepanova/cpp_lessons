/*Найдите в данной строке самое длинное слово и выведите его.

Входные данные: Вводится одна строка. Слова в ней отделены одним пробелом.

Выходные данные: Выведите самое длинное слово. Если таких слов несколько, то выводить нужно, которое встречается раньше.*/

//изменение

#include <iostream>
#include <string>

using namespace std;

int main() {

    string s, max_word;
    int max_length = 0;
    
    
    while (cin >> s)
    {
        if (s.length() > max_length)
        {
            max_length = s.length();
            max_word = s;
            
        }
        
    } 
    cout << max_word;
    
    return 0;
}
