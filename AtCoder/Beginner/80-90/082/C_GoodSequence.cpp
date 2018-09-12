#include <cstdio>
#include <map>
using namespace std;

int main()
{
  int n, tmp;
  map<int, int> m;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &tmp);
    m[tmp]++;
  }

  int count = 0;
  for (auto const &kv : m)
  {
    if (kv.first == kv.second)
      continue;
    else if (kv.second < kv.first)
      count += kv.second;
    else
      count += kv.second - kv.first;
  }

  printf("%d\n", count);

  return 0;
}