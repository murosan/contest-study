#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  int c = 700;

  for (int i = 0; i < 3; ++i) {
    if (s[i] == 'o') c += 100;
  }

  cout << c << endl;
}
