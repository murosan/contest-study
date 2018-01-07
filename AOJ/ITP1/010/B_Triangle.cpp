#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
  double a, b, c;
  cin >> a >> b >> c;
  c *= M_PI / 180.0;
  double sinC = sin(c);
  double cosC = cos(c);
  double S = 0.5 * a * b * sinC;
  double L = a + b + sqrt(a * a + b * b - 2 * a * b * cosC);
  double h = b * sinC;
  cout << fixed << setprecision(10) << S << endl;
  cout << L << endl;
  cout << h << endl;
  return 0;
}
