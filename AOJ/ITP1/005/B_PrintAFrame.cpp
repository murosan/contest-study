#include <iostream>
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
      {
        if (i == 1 || i == H || j == 1 || j == W)
          cout << "#";
        else
          cout << ".";
      }
      cout << endl;
    }
    cout << endl;
  }
}
