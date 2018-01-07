#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n, pt = 0, ph = 0;
  cin >> n;
  string t, h;
  for (int i = 0; i < n; i++)
  {
    cin >> t >> h;
    int cmp = t.compare(h);
    if (cmp == 0)
    {
      pt++;
      ph++;
    }
    else if (cmp > 0)
      pt += 3;
    else
      ph += 3;
  }
  cout << pt << " " << ph << endl;
}
