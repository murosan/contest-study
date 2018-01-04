#include <cstdio>
using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  int f[n][10], p[n][11];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < 10; j++)
      scanf("%d", &f[i][j]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 11; j++)
      scanf("%d", &p[i][j]);

  int res = -(1 << 30);
  for (int i = 1; i < 1 << 10; i++)
  {
    int cc = 0;
    for (int j = 0; j < n; j++)
    {
      int c = 0;
      for (int k = 0; k < 10; k++)
        if ((i >> k & 1) && f[j][k])
          c++;
      cc += p[j][c];
    }
    if (res < cc)
      res = cc;
  }

  printf("%d\n", res);

  return 0;
}
