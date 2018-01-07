#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
  double n;
  cin >> n;
  double x[int(n)], y[int(n)], a[int(n)];
  for (int i = 0; i < n; i++)
    cin >> x[i];
  for (int i = 0; i < n; i++)
  {
    cin >> y[i];
    a[i] = abs(x[i] - y[i]);
  }

  double p1 = 0;
  double p2 = 0;
  double p3 = 0;
  double p4 = 0;
  for (int i = 0; i < n; i++)
  {
    p1 += a[i];
    p2 += a[i] * a[i];
    p3 += a[i] * a[i] * a[i];
    if (p4 < a[i])
      p4 = a[i];
  }
  p2 = sqrt(p2);
  p3 = pow(p3, 1.0 / 3.0);

  cout << fixed << setprecision(10) << p1 << endl;
  cout << p2 << endl;
  cout << p3 << endl;
  cout << p4 << endl;
}
