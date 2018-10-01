#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int m = max(x, y);

  int ans = INT_MAX;
  for (int i = 0; i <= m; ++i) {
    int aa = max(a * (x - i), 0);
    int bb = max(b * (y - i), 0);
    ans = min(aa + bb + c * i * 2, ans);
  }

  cout << ans << endl;
}
