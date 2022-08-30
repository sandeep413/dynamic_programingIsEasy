#include <bits/stdc++.h>
using namespace std;
string LCS(string s1, string s2, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    string s;
    int i=m,j=n;
  while(i>=0 or j>=0)
  {
      if(s1[i-1]==s2[j-1])
      {
          s.push_back(s1[i-1]);
          i--;j--;
      }
      else
      {
          if(dp[i-1][j]>dp[i][j-1])
          {
              i--;
          }
          else
          j--;
      }
  }
  reverse(s.begin(),s.end());
  return s;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << LCS(s1, s2, s1.length(), s2.length());
    return 0;
}