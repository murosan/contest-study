#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;

using process = pair<string, int>;

int main()
{
  queue<process> que;

  int n, q, t;
  string name;
  cin >> n >> q;

  for (int i = 0; i < n; i++)
  {
    cin >> name >> t;
    que.push(make_pair(name, t));
  }

  int sum_of_time;

  while (!que.empty())
  {
    process p = que.front();
    que.pop();
    if (p.second > q)
    {
      p.second -= q;
      que.push(p);
      sum_of_time += q;
    }
    else
    {
      sum_of_time += p.second;
      cout << p.first << " " << sum_of_time << endl;
    }
  }

  return 0;
}
