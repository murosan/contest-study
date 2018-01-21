#include <cstdio>
#include <complex>

using namespace std;

int main() {
  int n, t[100001], x[100001], y[100001];
  scanf("%d", &n);
  t[0] = x[0] = y[0] = 0;

  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d", &t[i], &x[i], &y[i]);
  }

  for (int i = 1; i <= n; ++i) {
    int timeDiff = t[i] - t[i - 1];
    int distance = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
    if (distance > timeDiff || (distance - timeDiff) % 2 != 0) {
      printf("No\n");
      return 0;
    }
  }

  printf("Yes\n");
  return 0;
}
