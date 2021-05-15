//https://stepik.org/lesson/13029/step/9?unit=4381
//проверка Васей домашки Пети по словарю

#include <iostream>
#include <set>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

//функция для перевода строки в нижний регистр
string StringToLower(string s)
{  
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
} 

//функция для перевода строк во множестве в нижний регистр 
/*set <string> SetToLower(set <string>& s)
{
    string lk = "";
    set <string> lj;
    for (auto el : s)
        {
        lk = StringToLower(el);
        lj.insert(lk);
        } 
    return lj;
}
    
bool IsInLowerSet(set <string>& s, string i)
{
    set <string> lset = SetToLower(s);
    string lstring = StringToLower(i);
    
    if (lset.find(lstring) != lset.end())
    {
        return true;
    }
    return false;
}*/



//проверяем на наличие в словаре
bool IsInSet(set <string>& s, string i)
{   
    if (s.find(i) != s.end())
    {
        return true;
    }
    return false;
}

//функция для подсчета количества заглавных букв слове (=количество ударений)
int CapitalLetterCnt(string a)
{
    int cnt = 0;
    for (auto letter : a)
    {
        if (letter >= 'A' && letter <= 'Z') cnt++;
    }
    return cnt;
}

//функция для проверки пустой строки
bool IsStringNotEmpty(string a)
{
    return !a.empty();
} 


//функция для подсчета слов в строке, потом из этого количества будем вычитать слова без ошибок
int HomeworkWordCnt(string a)
{    
    int cnt = 1;
    for (auto c : a) 
    {
        if (c == ' ') cnt ++;
    }
    return cnt;
}



int main() {
    //считываем количество слов в словаре, сам словарь и его дубль в нижнем регистре
    
    int words_cnt = 0;
    cin >> words_cnt;
    set <string> dict;
    set <string> lower_set;
    for (int i = 0; i < words_cnt; i++)
    {
        string dict_word = "", lower_string = "";
        cin >> dict_word;
        dict.insert(dict_word);
        lower_string = StringToLower(dict_word);
        lower_set.insert(lower_string);
        
    }
    cin >> ws;
    
    size_t pos = 0;
    string delimiter_space = " ";
    string homework_word = "", lower_homework_word;
    string homework = "";
    
    //считываем строку с домашкой
    getline (cin, homework);

   if (IsStringNotEmpty(homework) == false) 
    {
        cout << 0;
        return 0;
    }
    
   int word_cnt = 0;
    word_cnt = HomeworkWordCnt(homework);
    
    //cout << SetToLower(homework);
    
    while ((pos = homework.find(delimiter_space)) != std::string::npos)
    {
        homework_word = homework.substr(0, pos);

        if (IsInSet(dict, homework_word) == true) 
        {
            word_cnt--;
        } 
        else if (IsInSet(dict, homework_word) == false)
        {
            lower_homework_word = StringToLower(homework_word);
            if ((IsInSet(lower_set, lower_homework_word) == false) && (CapitalLetterCnt(homework_word) == 1))
            {
                word_cnt--;
            }
        }
        homework.erase(0, pos + delimiter_space.length());
    } 
    if (IsInSet(dict, homework) == true) 
        {
            word_cnt--;
        } 
        else if (IsInSet(dict, homework) == false)
    {
        lower_homework_word = StringToLower(homework);
        if ((IsInSet(lower_set, lower_homework_word) == false) && (CapitalLetterCnt(homework) == 1))
            {
                word_cnt--;
            }
    } 
    cout << word_cnt;
 

        return 0;
}
