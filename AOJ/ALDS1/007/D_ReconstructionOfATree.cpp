#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, pos;
vector<int> pre, in, post;

void reconstruct(int l, int r)
{
  if (l >= r)
    return;
  int root = pre[pos++];
  int m = distance(in.begin(), find(in.begin(), in.end(), root));
  reconstruct(l, m);
  reconstruct(m + 1, r);
  post.push_back(root);
}

void solve()
{
  pos = 0;
  reconstruct(0, n);
  for (int i = 0; i < n - 1; i++)
    printf("%d ", post[i]);
  printf("%d\n", post[n - 1]);
}

int main()
{
  int tmp;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &tmp);
    pre.push_back(tmp);
  }
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &tmp);
    in.push_back(tmp);
  }

  solve();
  return 0;
}
