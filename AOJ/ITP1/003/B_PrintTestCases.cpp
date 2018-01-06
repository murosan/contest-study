#include <iostream>
using namespace std;

int main()
{
  for (int i = 1;; i++)
  {
    int x;
    cin >> x;
    if (x)
      cout << "Case " << i << ": " << x << endl;
    else
      return 0;
  }
}
