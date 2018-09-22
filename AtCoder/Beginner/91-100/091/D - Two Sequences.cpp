#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

int search(const ll n[], int len, ll comp) {
  int i = 0;
  int j = len;
  while (i < j) {
    int h = (i + j) >> 1;
    if (n[h] < comp) i = h + 1;
    else j = h;
  }
  return i;
}

int main() {
  int n;
  scanf("%d", &n);

  int tmpa[n], tmpb[n];
  for (int i = 0; i < n; i++) scanf("%d", &tmpa[i]);
  for (int i = 0; i < n; i++) scanf("%d", &tmpb[i]);

  ll ans = 0;
  for (int bit = 0; bit < 29; bit++) {
    ll t = 1 << bit;
    ll a[n], b[n];
    for (int i = 0; i < n; i++) {
      a[i] = tmpa[i] % (2 * t);
      b[i] = tmpb[i] % (2 * t);
    }
    sort(b, b + n);

    int c = 0;
    for (int i = 0; i < n; i++) {
      int c1 = search(b, n, t - a[i]);
      int c2 = search(b, n, 2 * t - a[i]);
      int c3 = search(b, n, 3 * t - a[i]);
      int c4 = search(b, n, 4 * t - a[i]);
      c = (c + c2 - c1 + c4 - c3) % 2;
    }

    if (c == 1) ans += t;
  }

  printf("%lld\n", ans);
  return 0;
}
