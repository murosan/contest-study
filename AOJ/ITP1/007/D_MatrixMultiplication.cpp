#include <iostream>

using namespace std;

int main()
{
  int n, m, l;
  cin >> n >> m >> l;
  long long a[n][m];
  long long b[m][l];
  long long c[n][l];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];

  for (int i = 0; i < m; i++)
    for (int j = 0; j < l; j++)
      cin >> b[i][j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < l; j++)
      c[i][j] = 0;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < l; j++)
      for (int k = 0; k < m; k++)
        c[i][j] += a[i][k] * b[k][j];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < l; j++)
    {
      cout << c[i][j];
      if (j != l - 1)
        cout << " ";
    }
    cout << endl;
  }
  return 0;
}
