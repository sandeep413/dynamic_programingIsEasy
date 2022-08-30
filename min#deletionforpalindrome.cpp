#include<bits/stdc++.h>
using namespace std;
int mindeletion(string s1,string s2,int a,int b)
{
    int dp[a+1][b+1];
    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            if(s1[i-1]==s2[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

        }
    }
    return s1.length()-dp[a][b];
}
int main()
{
    string s1;
    cin>>s1;
    string s2=s1;
    s2=s1;
    reverse(s2.begin(),s2.end());
    cout<<mindeletion(s1,s2,s1.length(),s2.length());
    return 0;
}