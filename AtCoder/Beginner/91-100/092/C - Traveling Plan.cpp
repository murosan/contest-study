#include <cstdio>
#include <complex>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  int a[n + 2], b[n + 2];
  a[0] = 0;
  a[n + 1] = 0;
  b[0] = 0;

  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }

  for (int i = 1; i <= n + 1; i++) {
    b[i] = b[i - 1] + abs(a[i] - a[i - 1]);
  }

  int total = b[n + 1];

  for (int i = 1; i <= n; i++) {
    int prev = a[i - 1];
    int cur = a[i];
    int next = a[i + 1];
    int d = (abs(cur - prev) - abs(prev - next)) + abs(cur - next);
    printf("%d\n", total - d);
  }

  return 0;
}
