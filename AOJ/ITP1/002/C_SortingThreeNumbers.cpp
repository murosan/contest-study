#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main()
{
  vector<int> v;
  int n = 3;
  while (n--)
  {
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  cout << v[0] << " " << v[1] << " " << v[2] << endl;
  return 0;
}
