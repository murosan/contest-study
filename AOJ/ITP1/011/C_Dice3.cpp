#include <iostream>
#include <algorithm>
using namespace std;

struct Dise
{
  int top;
  int bottom;
  int north;
  int east;
  int south;
  int west;
  void toNorth()
  {
    int t = top, b = bottom, n = north, s = south;
    top = s, bottom = n, north = t, south = b;
  }
  void toEast()
  {
    int t = top, b = bottom, e = east, w = west;
    top = w, bottom = e, east = t, west = b;
  }
  void toSouth()
  {
    int t = top, b = bottom, n = north, s = south;
    top = n, bottom = s, north = b, south = t;
  }
  void toWest()
  {
    int t = top, b = bottom, e = east, w = west;
    top = e, bottom = w, west = t, east = b;
  }
  void toTop(int a)
  {
    if (a == north)
      toSouth();
    else if (a == east)
      toWest();
    else if (a == south)
      toNorth();
    else if (a == west)
      toEast();
    else if (a == bottom)
    {
      toNorth();
      toNorth();
    }
  }
  void spin()
  {
    int n = north, e = east, s = south, w = west;
    north = w, east = n, south = e, west = s;
  }
} d1, d2;

int main()
{
  int n[2][6];
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 6; j++)
    {
      cin >> n[i][j];
    }
  d1.top = n[0][0], d1.south = n[0][1], d1.east = n[0][2],
  d1.west = n[0][3], d1.north = n[0][4], d1.bottom = n[0][5];
  d2.top = n[1][0], d2.south = n[1][1], d2.east = n[1][2],
  d2.west = n[1][3], d2.north = n[1][4], d2.bottom = n[1][5];

  sort(n[0], n[0] + 6);
  sort(n[1], n[1] + 6);
  for (int i = 0; i < 6; i++)
    if (n[0][i] != n[1][i])
    {
      cout << "No" << endl;
      return 0;
    }

  d2.toTop(d1.top);
  while (d2.south != d1.south)
  {
    d2.spin();
  }

  if (d1.north == d2.north && d1.east == d2.east && d1.west == d2.west)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
