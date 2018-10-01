#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  int sum = 0;
  vector<int> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    sum += v[i];
  }

  int min = *min_element(v.begin(), v.end());

  cout << n + (x - sum) / min << endl;
}
