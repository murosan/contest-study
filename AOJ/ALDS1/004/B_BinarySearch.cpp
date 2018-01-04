#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n, q, tmp;
  set<int> s;

  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &tmp);
    s.insert(tmp);
  }

  scanf("%d", &q);
  vector<int> t(q);
  for (int i = 0; i < q; i++)
    scanf("%d", &t[i]);

  sort(t.begin(), t.end());

  int count = 0;
  for (set<int>::iterator itr = s.begin(); itr != s.end(); itr++)
    if (binary_search(t.begin(), t.end(), *itr))
      count++;

  printf("%d\n", count);
  return 0;
}
