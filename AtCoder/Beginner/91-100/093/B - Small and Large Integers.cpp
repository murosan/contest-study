#include <cstdio>
#include <set>

using namespace std;

int main() {
  int a, b, k;
  scanf("%d%d%d", &a, &b, &k);

  set<int> s;

  int aa = a;
  int bb = b;
  for (int i = 0; i < k; ++i) {
    if (aa <= b) s.insert(aa);
    if (bb >= a) s.insert(bb);
    ++aa;
    --bb;
  }

  for (int i : s) {
    printf("%d\n", i);
  }
  return 0;
}
