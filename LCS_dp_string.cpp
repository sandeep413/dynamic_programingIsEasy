#include<iostream>
using namespace std;
int LCS_DP_string(string s1,string s2,int m,int n)
{
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=0;
        }
    }
    return dp[m][n];
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<LCS_DP_string(s1,s2,s1.length(),s2.length());
    return 0;
}


// Longest common Substring

// #include<iostream>
// using namespace std;
// int LCSubstring(string s1,string s2,int n1,int n2)
// {
//     int dp[n1+1][n2+1];
//     for(int i=0;i<=n1;i++)
//     {
//     for(int j=0;j<=n2;j++)
//       {
//          if(i==0||j==0)
//          dp[i][j]=0;
//       }
    
//     }
//     for(int i=1;i<=n1;i++)
//     {
//         for(int j=1;j<=n2;j++)
//         {
//             if(s1[i-1]==s2[j-1])
//             {
//                 dp[i][j]=1+dp[i-1][j-1];
//             }
//             else
//             {
//                 dp[i][j]=0;
//             }
//         }
//     }
//     return dp[n1][n2];
// }
// int main()
// {
//     string s1="abcde";
//     string s2="abcdj";
//     cout<<LCSubstring(s1,s2,s1.length(),s2.length());
//     return 0;
// }