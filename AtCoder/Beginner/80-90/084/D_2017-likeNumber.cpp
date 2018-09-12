#include <cstdio>
using namespace std;

int main()
{
  bool f[100001];
  int c[100001];

  for (int i = 0; i <= 100000; i++)
  {
    f[i] = false;
    c[i] = 0;
  }

  for (int i = 2; i <= 100000; i++)
    if (!f[i])
      for (int j = i + i; j <= 100000; j += i)
        f[j] = true;

  for (int i = 3; i <= 100000; i += 2)
    if (!f[i] && !f[(i + 1) / 2])
      c[i]++;

  for (int i = 3; i <= 100000; i++)
    c[i] += c[i - 1];

  int q, l, r;
  scanf("%d", &q);

  for (int i = 0; i < q; i++)
  {
    scanf("%d%d", &l, &r);
    printf("%d\n", c[r] - c[l - 1]);
  }

  return 0;
}
