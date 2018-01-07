#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int n, h, ai, bi;
  vector<int> a, b;
  scanf("%d%d", &n, &h);

  for (int i = 0; i < n; i++)
  {
    scanf("%d%d", &ai, &bi);
    a.push_back(ai);
    b.push_back(bi);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int maxA = a.back();
  int maxB = b.back();

  int attackCount = 0;
  while (h > 0)
  {
    if (maxA >= maxB)
    {
      int c = h / maxA;
      if (h % maxA != 0)
        c++;
      h -= c * maxA;
      attackCount += c;
    }
    else
    {
      h -= maxB;
      attackCount++;
      b.pop_back();
      maxB = b.back();
    }
  }

  printf("%d\n", attackCount);
  return 0;
}
