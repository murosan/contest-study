#include <iostream>
#include <string>
using namespace std;

int main()
{
  while (true)
  {
    int a, b;
    string op;
    cin >> a >> op >> b;
    if (op == "?")
      return 0;

    if (op == "+")
      cout << a + b << endl;
    else if (op == "-")
      cout << a - b << endl;
    else if (op == "*")
      cout << a * b << endl;
    else
      cout << a / b << endl;
  }
  return 0;
}