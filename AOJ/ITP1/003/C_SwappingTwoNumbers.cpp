#include <iostream>
using namespace std;

int main()
{
  while (true)
  {
    int x, y;
    cin >> x >> y;
    if (x || y)
      if (x < y)
        cout << x << " " << y << endl;
      else
        cout << y << " " << x << endl;
    else
      return 0;
  }
}