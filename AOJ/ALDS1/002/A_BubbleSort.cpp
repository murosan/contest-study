#include <iostream>
#include <vector>
using namespace std;

// void bubbleSort(vector<int> v, int n)
// {
//   for (int i = 0; i < n; i++)
//     for (int j = n - 1; j > i; j--)
//       if (v[j] < v[j - 1])
//         swap(v[j], v[j - 1]);
// }

int main()
{
  int n, tmp;
  vector<int> a;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    cin >> tmp;
    a.push_back(tmp);
  }

  int flag = 1;
  int swapCount = 0;
  int sortedIndex = 0;

  while (flag == 1)
  {
    flag = 0;
    for (int i = n - 1; i > sortedIndex; --i)
      if (a[i] < a[i - 1])
      {
        swap(a[i], a[i - 1]);
        swapCount++;
        flag = 1;
      }
    sortedIndex++;
  }

  for (int i = 0; i < n - 1; ++i)
    printf("%d ", a[i]);
  printf("%d\n", a[n - 1]);
  printf("%d\n", swapCount);
  return 0;
}
