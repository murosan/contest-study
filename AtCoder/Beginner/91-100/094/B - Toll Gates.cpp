#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, x;
  cin >> n >> m >> x;

  int a[101];
  for (int i = 0; i <= 100; ++i) a[i] = 0;
  for (int i = 0; i < m; ++i) {
    int in;
    scanf("%d", &in);
    a[in] = 1;
  }

  int cost1 = 0;
  int xx = x;
  while (xx != 0) {
    cost1 += a[xx];
    --xx;
  }

  int cost2 = 0;
  xx = x;
  while (xx != n) {
    cost2 += a[xx];
    ++xx;
  }

  cout << (cost1 < cost2 ? cost1 : cost2) << endl;
}
