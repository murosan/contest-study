#include <cstdio>
#include <cmath>
using namespace std;

struct Point
{
  double x;
  double y;
};

double sin60 = sqrt(3.0) / 2.0;
double cos60 = 1.0 / 2.0;

void kock(int depth, Point p1, Point p2)
{
  if (depth == 0)
    return;

  Point s, t, u;
  s.x = (p1.x * 2 + p2.x) / 3;
  s.y = (p1.y * 2 + p2.y) / 3;
  t.x = (p1.x + p2.x * 2) / 3;
  t.y = (p1.y + p2.y * 2) / 3;
  u.x = (t.x - s.x) * cos60 - (t.y - s.y) * sin60 + s.x;
  u.y = (t.x - s.x) * sin60 + (t.y - s.y) * cos60 + s.y;

  kock(depth - 1, p1, s);
  printf("%.10f %.10f\n", s.x, s.y);
  kock(depth - 1, s, u);
  printf("%.10f %.10f\n", u.x, u.y);
  kock(depth - 1, u, t);
  printf("%.10f %.10f\n", t.x, t.y);
  kock(depth - 1, t, p2);
}

int main()
{
  int n;
  scanf("%d", &n);

  Point s, g = {100, 0};

  printf("%.10f %.10f\n", s.x, s.y);
  kock(n, s, g);
  printf("%.10f %.10f\n", g.x, g.y);

  return 0;
}
