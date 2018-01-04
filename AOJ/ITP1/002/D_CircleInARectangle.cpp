#include <iostream>

using namespace std;

bool inRange(int x, int y, int maxX, int maxY)
{
  return 0 <= x && x <= maxX && 0 <= y && y <= maxY;
}

int main()
{
  int W, H, x, y, r;
  cin >> W >> H >> x >> y >> r;
  if (r <= x && x <= W - r && r <= y && y <= H - r)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
