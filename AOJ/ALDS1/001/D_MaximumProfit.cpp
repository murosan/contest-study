#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, tmp;
  vector<int> r;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> tmp;
    r.push_back(tmp);
  }

  int minR = min(r[0], r[1]);
  int maxDiff = r[1] - r[0];
  for (int i = 2; i < n; i++)
  {
    maxDiff = max(maxDiff, r[i] - minR);
    minR = min(minR, r[i]);
  }

  cout << maxDiff << endl;
  return 0;
}
