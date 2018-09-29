#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, x;
  cin >> a >> b >> x;

  if (a > x || a + b < x) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
}
