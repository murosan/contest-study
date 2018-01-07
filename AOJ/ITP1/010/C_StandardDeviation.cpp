#include <iostream>
#include <iomanip>
#include <complex>
#include <cmath>
using namespace std;

int main()
{
  while (true)
  {
    double n;
    cin >> n;
    if (n == 0)
      return 0;

    double s[int(n)];
    double avg = 0;
    for (int i = 0; i < n; ++i)
    {
      cin >> s[i];
      avg += s[i];
    }
    avg /= n;

    double dispersion = 0;
    for (int i = 0; i < n; ++i)
      dispersion += pow(avg - s[i], 2);
    dispersion /= n;

    cout << fixed << setprecision(10) << abs(sqrt(dispersion)) << endl;
  }
  return 0;
}
