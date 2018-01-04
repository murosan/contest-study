#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, tmp;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < n; ++i)
  {
    cin >> tmp;
    a.push_back(tmp);
  }

  int swapCount = 0;
  for (int i = 0; i < n; ++i)
  {
    int minIndex = i;
    for (int j = i; j < n; ++j)
      if (a[j] < a[minIndex])
        minIndex = j;
    if (a[i] > a[minIndex])
    {
      swapCount++;
      swap(a[i], a[minIndex]);
    }
  }

  for (int i = 0; i < n - 1; i++)
    printf("%d ", a[i]);
  printf("%d\n", a[n - 1]);
  printf("%d\n", swapCount);
  return 0;
}
