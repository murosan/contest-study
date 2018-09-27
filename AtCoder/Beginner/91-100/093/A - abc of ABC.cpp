#include <cstdio>
#include <string>

using namespace std;

bool contains(const char *s, char c) {
  return s[0] == c || s[1] == c || s[2] == c;
}

int main() {
  char s[3];
  scanf("%s", s);

  if (contains(s, 'a') && contains(s, 'b') && contains(s, 'c')) {
    printf("Yes\n");
    return 0;
  }

  printf("No\n");
  return 0;
}
