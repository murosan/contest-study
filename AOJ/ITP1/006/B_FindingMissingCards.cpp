#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin >> n;
  // S=> 0, H=> 1, C=> 2, D=> 3
  bool c[4][13];
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 13; j++)
      c[i][j] = false;

  for (int i = 0; i < n; i++)
  {
    string mark;
    int num;
    cin >> mark >> num;
    num--;
    if (mark == "S")
      c[0][num] = true;
    else if (mark == "H")
      c[1][num] = true;
    else if (mark == "C")
      c[2][num] = true;
    else
      c[3][num] = true;
  }

  vector<pair<int, int>> m;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 13; j++)
      if (!c[i][j])
        m.push_back(make_pair(i, j));

  for (int i = 0; i < m.size(); i++)
    if (m[i].first == 0)
      cout << "S " << m[i].second + 1 << endl;
    else if (m[i].first == 1)
      cout << "H " << m[i].second + 1 << endl;
    else if (m[i].first == 2)
      cout << "C " << m[i].second + 1 << endl;
    else
      cout << "D " << m[i].second + 1 << endl;

  return 0;
}
