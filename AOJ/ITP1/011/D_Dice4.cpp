#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

struct Dice
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
  bool equals(Dice d)
  {
    int n1[6] = {top, bottom, north, west, south, east};
    int n2[6] = {d.top, d.bottom, d.north, d.west, d.south, d.east};
    bool matchNumbers = true;
    for (int i = 0; i < 6 && matchNumbers; i++)
      matchNumbers = find(begin(n2), end(n2), n1[i]) != end(n2);
    if (!matchNumbers)
      return false;

    toTop(d.top);
    int count = 0;
    while (south != d.south && count <= 3)
    {
      spin();
      count++;
    }

    if (top == d.top && bottom == d.bottom &&
        north == d.north && east == d.east &&
        south == d.south && west == d.west)
      return true;
    else
      return false;
  }
};

int main()
{
  int n;
  cin >> n;
  Dice dices[n];
  for (int i = 0; i < n; i++)
  {
    dices[i] = Dice{};
    cin >> dices[i].top >> dices[i].south >> dices[i].east;
    cin >> dices[i].west >> dices[i].north >> dices[i].bottom;
  }

  bool notEqual = true;
  for (int i = 0; i < n && notEqual; i++)
    for (int j = i + 1; j < n && notEqual; j++)
      notEqual = !dices[i].equals(dices[j]);

  if (notEqual)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
