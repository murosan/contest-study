#include <cstdio>
using namespace std;

int main()
{
  int n, y;
  scanf("%d%d", &n, &y);
  y /= 1000;

  for (int i = n; i >= 0; i--)
    for (int j = n - i; j >= 0; j--)
    {
      int k = n - i - j;
      if (10 * i + 5 * j + 1 * k == y)
      {
        printf("%d %d %d\n", i, j, k);
        return 0;
      }
    }

  printf("-1 -1 -1\n");
  return 0;
}
