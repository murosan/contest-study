#include <iostream>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  long long a[n][m];
  long long b[m];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];

  for (int j = 0; j < m; j++)
    cin >> b[j];

  for (int i = 0; i < n; i++)
  {
    long long c = 0;
    for (int j = 0; j < m; j++)
      c += (a[i][j] * b[j]);
    cout << c << endl;
  }

  return 0;
}
