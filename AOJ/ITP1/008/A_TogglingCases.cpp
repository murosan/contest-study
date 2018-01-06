#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main()
{
  string s;
  getline(cin, s);

  locale loc;
  char c;
  for (string::size_type i = 0; i < s.length(); i++)
  {
    c = s[i];
    if (isupper(c, loc))
      c = tolower(c, loc);
    else if (islower(c, loc))
      c = toupper(c, loc);
    cout << c;
  }

  cout << endl;
  return 0;
}
