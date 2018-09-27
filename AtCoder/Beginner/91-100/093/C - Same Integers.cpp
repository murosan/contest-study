#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);

  int m = max(a, max(b, c));

  int qa = (m - a) / 2;
  int qb = (m - b) / 2;
  int qc = (m - c) / 2;

  int ans = qa + qb + qc;

  a = m - a - qa * 2;
  b = m - b - qb * 2;
  c = m - c - qc * 2;

  int sum = a + b + c;
  if (sum == 0) {
    printf("%d\n", ans);
    return 0;
  }

  if (sum == 2) {
    printf("%d\n", ans + 1);
    return 0;
  }

  printf("%d\n", ans + 2);
  return 0;
}
