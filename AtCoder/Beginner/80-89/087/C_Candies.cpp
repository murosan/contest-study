#include <cstdio>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  int a[2][n];
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  for (int i = 1; i < n; ++i) {
    a[0][i] += a[0][i - 1];
    a[1][n - i - 1] += a[1][n - i];
  }

  int max = 0;
  for (int i = 0; i < n; ++i) {
    int sum = a[0][i] + a[1][i];
    if (sum > max) max = sum;
  }

  printf("%d\n", max);

  return 0;
}
