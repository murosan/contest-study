#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  string str, order;
  int n;
  cin >> str >> n;

  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> order >> a >> b;
    if (order == "print")
      cout << str.substr(a, b - a + 1) << endl;
    else if (order == "reverse")
      reverse(&str[a], &str[b + 1]);
    else
    {
      string s;
      cin >> s;
      str.replace(a, b - a + 1, s);
    }
  }

  return 0;
}
