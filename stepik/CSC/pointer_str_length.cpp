#include <iostream>
#include <string>

using namespace std;

unsigned strlen(const char *str)
{
    int cnt = 0;
  while(*str != '\0')
  {
      cnt++;
      str++;
  }
  return cnt;
}


int main()
{
   string s = "ggegegdbdbdbe";
   cout << strlen(s.c_str());
    return 0;
}
