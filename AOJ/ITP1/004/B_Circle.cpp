#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
  double r;
  cin >> r;
  printf("%.10f ", r * r * M_PI);
  printf("%.10f\n", 2 * r * M_PI);
  return 0;
}
