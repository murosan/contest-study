#include <iostream>

using namespace std;

int main()
{
  int x, y, a, b;
  cin >> x >> y;

  if (x < y)
    a = y, b = x;
  else
    a = x, b = y;

  while (a % b != 0)
  {
    int tmp_a = a;
    a = b, b = tmp_a % b;
  }

  cout << b << endl;
  return 0;
}