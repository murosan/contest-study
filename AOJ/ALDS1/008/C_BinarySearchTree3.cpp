#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Node
{
  int key;
  Node *parent, *left, *right;
};

Node *root, *nil;

void insert(int i)
{
  Node *n = (Node *)malloc(sizeof(Node));
  n->key = i;
  n->left = nil;
  n->right = nil;

  Node *node = root;
  Node *parent = nil;
  while (node != nil)
  {
    parent = node;
    if (n->key < node->key) node = node->left;
    else node = node->right;
  }
  n->parent = parent;

  if (parent == nil) root = n;
  else if (n->key < parent->key) parent->left = n;
  else parent->right = n;
}

Node *find(Node *n, int i)
{
  if (n == nil || n->key == i) return n;
  if (i < n->key) return find(n->left, i);
  else return find(n->right, i);
}

Node *getNext(Node *n)
{
  if (n->left != nil) return getNext(n->left);
  return n;
}

void del(Node *n, int i)
{
  Node *node = find(n, i);
  if (node == nil) return;

  if (node->left != nil && node->right != nil)
  {
    Node *next = getNext(node->right);
    node->key = next->key;
    del(next, next->key);
    return;
  }

  Node *p = node->parent;
  Node *l = p->left;
  Node *r = p->right;

  if (node->left == nil && node->right == nil)
    if (l == node) p->left = nil;
    else p->right = nil;
  else
  {
    Node *child = (node->left == nil) ? node->right : node->left;
    if (node == l) p->left = child;
    else p->right = child;
    child->parent = p;
  }

  free(node);
}

void preorderPrint(Node *n)
{
  if (n == nil) return;
  printf(" %d", n->key);
  preorderPrint(n->left);
  preorderPrint(n->right);
}

void inorderPrint(Node *n)
{
  if (n == nil) return;
  inorderPrint(n->left);
  printf(" %d", n->key);
  inorderPrint(n->right);
}

int main()
{
  int m, num;
  char order[7];
  scanf("%d", &m);

  for (int i = 0; i < m; i++)
  {
    scanf("%s", order);
    if (order[0] == 'p')
    {
      inorderPrint(root);
      printf("\n");
      preorderPrint(root);
      printf("\n");
    }
    else
    {
      scanf("%d", &num);
      if (order[0] == 'i') insert(num);
      else if (order[0] == 'f')
        if (find(root, num) != nil) printf("yes\n");
        else printf("no\n");
      else del(root, num);
    }
  }

  return 0;
}
