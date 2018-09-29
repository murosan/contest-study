#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void calc(ll a, ll b) {
  if (a == b || a + 1 == b) {
    printf("%lld\n", 2 * a - 2);
    return;
  }

  ll r = sqrt(a * b);
  if (r * r == a * b) --r;

  if (r * (r + 1) >= a * b) {
    printf("%lld\n", 2 * r - 2);
    return;
  }

  printf("%lld\n", 2 * r - 1);
}

int main() {
  int q;
  scanf("%d", &q);

  for (int i = 0; i < q; ++i) {
    ll a, b;
    scanf("%lld%lld", &a, &b);
    if (a > b) swap(a, b);
    calc(a, b);
  }
}
