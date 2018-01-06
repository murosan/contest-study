#include <iostream>
using namespace std;

int main()
{
  int r, c;
  cin >> r >> c;
  int rc[r + 1][c];
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      rc[i][j] = 0;
      if (i == 0)
        rc[r][j] = 0;

      cin >> rc[i][j];
      rc[r][j] += rc[i][j];
    }
  }

  for (int i = 0; i <= r; i++)
  {
    int col_sum = 0;
    for (int j = 0; j < c; j++)
    {
      cout << rc[i][j] << " ";
      col_sum += rc[i][j];
    }
    cout << col_sum << endl;
  }
  return 0;
}