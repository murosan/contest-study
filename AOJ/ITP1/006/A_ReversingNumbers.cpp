#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n, input;
  cin >> n;

  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    v.push_back(input);
  }

  reverse(v.begin(), v.end());

  for (int i = 0; i < n - 1; i++)
    cout << v[i] << " ";
  cout << v[n - 1] << endl;
  return 0;
}