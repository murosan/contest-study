#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  while (true)
  {
    int H, W;
    cin >> H >> W;
    if (!H)
      return 0;

    for (int i = 1; i <= H; i++)
    {
      for (int j = 1; j <= W; j++)
        cout << "#";
      cout << endl;
    }
    cout << endl;
  }
}