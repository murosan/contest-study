#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string join(const vector<int> &v, const char *delim = 0)
{
  string s;
  if (!v.empty())
  {
    s += to_string(v[0]);
    for (decltype(v.size()) i = 1, c = v.size(); i < c; ++i)
    {
      if (delim)
        s += delim;
      s += to_string(v[i]);
    }
  }
  return s;
}

int main()
{
  int n, x;
  vector<int> a;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    a.push_back(x);
  }
  cout << join(a, " ") << endl;

  for (int i = 1; i < n; i++)
  {
    for (int j = i - 1; j >= 0; j--)
      if (a[j] > a[j + 1])
        swap(a[j], a[j + 1]);
      else
        break;
    cout << join(a, " ") << endl;
  }
  return 0;
}
