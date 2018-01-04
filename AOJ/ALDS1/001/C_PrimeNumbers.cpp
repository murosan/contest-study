#include <iostream>
#include <complex>

using namespace std;

bool isPrimeNumber(int n)
{
  if (n == 2)
    return true;

  if (n < 2 || n % 2 == 0)
    return false;

  int i = 3;
  while (i <= sqrt(n))
    if (n % i == 0)
      return false;
    else
      i += 2;

  return true;
}

int main()
{
  int n, count = 0, tmp;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> tmp;
    if (isPrimeNumber(tmp))
      count++;
  }

  cout << count << endl;
  return 0;
}
