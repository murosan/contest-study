#include <bits/stdc++.h>

using namespace std;

int main() {
  unsigned int n;
  scanf("%u", &n);

  vector<int> v1(n), v2(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v1[i]);
    v2[i] = v1[i];
  }

  sort(v1.begin(), v1.end());

  auto len = v1.size();
  int center1 = v1[len / 2 - 1];
  int center2 = v1[len / 2];

  for (auto v:v2) {
    if (v <= center1) printf("%d\n", center2);
    else printf("%d\n", center1);
  }
}
