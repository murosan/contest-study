#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> zAlgo(const string &s)
{
  int n = s.size();
  vector<int> z(n, 0);
  z[0] = n;
  int l = 0, r = 0;

  for (int i = 1; i < n; i++)
  {
    if (i > r)
    {
      l = r = i;
      while (r < n && s[r - l] == s[r])
        r++;
      z[i] = r - l;
      r--;
    }
    else
    {
      int k = i - l;
      if (z[k] < r + 1 - i)
        z[i] = z[k];
      else
      {
        l = i;
        while (r < n && s[r - l] == s[r])
          r++;
        z[i] = r - l;
        r--;
      }
    }
  }

  return z;
}

constexpr long long mod = 1000000007ll;

int main()
{
  string s;
  cin >> s;

  int n = s.size();
  vector<long long> dp(n, 0);
  long long ans = 0;
  dp[0] = 1;
  for (int i = 0; i < n && n - 2 * i > 0; i++)
  {
    int len = n - 2 * i;
    string sub = s.substr(i, len);
    auto z = zAlgo(sub);
    for (int j = 1; j <= len / 2; j++)
    {
      if (z[len - j] == j)
      {
        dp[i + j] = (dp[i + j] + dp[i]) % mod;
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    ans = (ans + dp[i]) % mod;
  }
  cout << ans << endl;
  return 0;
}
