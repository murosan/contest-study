#include <cstdio>
#include <vector>
using namespace std;

int partition(int a[], int p, int r)
{
  int x = a[r];
  int i = p - 1;
  for (int j = p; j < r; j++)
    if (a[j] <= x)
    {
      i++;
      swap(a[i], a[j]);
    }
  swap(a[i + 1], a[r]);
  return i + 1;
}

int main()
{
  int n;
  scanf("%d", &n);

  int a[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  int index = partition(a, 0, n - 1);

  for (int i = 0; i < n - 1; i++)
    if (i == index)
      printf("[%d] ", a[i]);
    else
      printf("%d ", a[i]);
  printf("%d\n", a[n - 1]);
  return 0;
}
