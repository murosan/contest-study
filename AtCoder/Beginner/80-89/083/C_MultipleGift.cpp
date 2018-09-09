#include <cstdio>
using namespace std;

using int64 = long long;

int main()
{
  long long x, y;
  scanf("%lld%lld", &x, &y);

  long long count = 1;
  while (x * 2 <= y)
  {
    count++;
    x *= 2;
  }

  printf("%lld\n", count);

  return 0;
}