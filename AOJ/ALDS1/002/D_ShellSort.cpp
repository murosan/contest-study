#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<int> v, string delim)
{
  for (int i = 0; i < v.size() - 1; i++)
    cout << v[i] << delim;
  cout << v[v.size() - 1] << endl;
}

vector<int> shellSort(vector<int> v, int size)
{
  int count = 0;
  int m = 1;
  vector<int> g = {1};
  while (g[0] * 3 + 1 < size)
  {
    g.insert(g.begin(), g[0] * 3 + 1);
    m++;
  }

  // print m and g[]
  cout << g.size() << endl;
  printVec(g, " ");

  for (int i = 0; i < m; i++)
  {
    // insertion sort
    for (int j = 0; j < size; j++)
    {
      int h = g[i];
      for (int k = j - h; k >= 0; k -= h)
        if (v[k] > v[k + h])
        {
          swap(v[k], v[k + h]);
          count++;
        }
        else
          break;
    }
  }

  cout << count << endl;
  return v;
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  printVec(shellSort(a, n), "\n");
  return 0;
}
