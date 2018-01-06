#include <iostream>
using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  int count = 0;
  for (; a <= b; a++)
  {
    if (c % a == 0)
      count++;
  }
  cout << count << endl;
  return 0;
}
