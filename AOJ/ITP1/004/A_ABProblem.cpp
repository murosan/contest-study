#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  cout << a / b << " " << a % b << " ";
  printf("%7f", double(a) / double(b));
  cout << endl;
  return 0;
}
