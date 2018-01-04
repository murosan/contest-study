#include <cstdio>
using namespace std;

struct UnionFind
{
  int parent[];
  int rank[];

  int root(int i)
  {
    if (rank[i] == i)
      return i;
    parent[i] = root(parent[i]);
    return parent[i];
  }

  bool same(int x, int y)
  {
    return root(x) == root(y);
  }

  void unite(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return;

    if (parent[x] < parent[y])
      parent[x] = y;
    else
    {
      parent[y] = x;
      if (parent[x] == parent[y])
        parent[x]++;
    }
  }
};