#include <bits/stdc++.h>

using namespace std;

int near(vector<int> v, int i) {
  auto index1 = lower_bound(v.begin() + 1, v.end() - 1, i) - v.begin();
  auto index2 = index1 - 1;
  return abs(v[index1] - i) < abs(v[index2] - i) ? v[index1] : v[index2];
}

int main() {
  unsigned int n;
  scanf("%u", &n);

  vector<int> v(n);
  for (int i = 0; i < n; ++i) scanf("%d", &v[i]);

  sort(v.begin(), v.end());

  int last = v.back();
  if (last % 2 == 1) ++last;

  printf("%d %d\n", v.back(), near(v, last / 2));
}
