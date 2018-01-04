#include <iostream>
using namespace std;

int main()
{
  int s;
  cin >> s;
  cout << s / 3600;
  cout << ":";
  cout << (s % 3600) / 60;
  cout << ":";
  cout << s % 60 << endl;
  return 0;
}
