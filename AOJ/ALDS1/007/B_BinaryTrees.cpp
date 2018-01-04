#include <cstdio>
#include <algorithm>
using namespace std;
#define Nil -1

struct Tree
{
  int parent, left, right;
};

int setHeight(int id, int h[], Tree t[])
{
  int leftHeight = 0, rightHeight = 0;
  if (t[id].left != Nil)
    leftHeight = setHeight(t[id].left, h, t) + 1;
  if (t[id].right != Nil)
    rightHeight = setHeight(t[id].right, h, t) + 1;

  return h[id] = max(leftHeight, rightHeight);
}

void setDepth(int depth, int id, int d[], Tree t[])
{
  d[id] = depth;
  if (t[id].left != Nil)
    setDepth(depth + 1, t[id].left, d, t);
  if (t[id].right != Nil)
    setDepth(depth + 1, t[id].right, d, t);
}

void print(int id, Tree t[], int dep[], int height[])
{
  int p = t[id].parent;
  printf("node %d: ", id);
  printf("parent = %d, ", p);

  if (p == Nil || t[p].left == Nil || t[p].right == Nil)
    printf("sibling = -1, ");
  else if (t[p].left == id)
    printf("sibling = %d, ", t[p].right);
  else
    printf("sibling = %d, ", t[p].left);

  bool l = t[id].left != Nil;
  bool r = t[id].right != Nil;
  int degree = (l && r) ? 2 : ((l || r) ? 1 : 0);
  printf("degree = %d, ", degree);
  printf("depth = %d, ", dep[id]);
  printf("height = %d, ", height[id]);

  if (t[id].parent == Nil)
    printf("root\n");
  else if (t[id].left != Nil || t[id].right != Nil)
    printf("internal node\n");
  else
    printf("leaf\n");
}

int main()
{
  int n, dep[25], height[25];
  Tree trees[25];
  scanf("%d", &n);

  for (int i = 0; i < 25; i++)
  {
    trees[i].parent = trees[i].left = trees[i].right = Nil;
    dep[i] = 0;
    height[i] = 0;
  }

  for (int i = 0; i < n; i++)
  {
    int id, left, right;
    scanf("%d%d%d", &id, &left, &right);
    trees[id].left = left;
    trees[id].right = right;
    if (left != Nil)
      trees[left].parent = id;
    if (right != Nil)
      trees[right].parent = id;
  }

  int root;
  for (int i = 0; i < n; i++)
    if (trees[i].parent == -1)
      root = i;

  setHeight(root, height, trees);
  setDepth(0, root, dep, trees);

  for (int i = 0; i < n; i++)
    print(i, trees, dep, height);

  return 0;
}
