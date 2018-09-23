#include <cstdio>

using namespace std;

int width = 100;

int print(char c1, char c2, int count) {
  for (int i = 0; i < width / 2; ++i) {
    for (int j = 0; j < width; ++j) {
      if (count != 0 && i % 2 && j % 2) {
        printf("%c", c1);
        count--;
      } else {
        printf("%c", c2);
      }
    }
    printf("\n");
  }
  return 0;
}

int main() {
  int a, b;
  scanf("%d%d", &a, &b);

  a--;
  b--;

  printf("100 100\n");
  print('.', '#', a);
  print('#', '.', b);

  return 0;
}
