#include<bits/stdc++.h>
using namespace std;
int lic(string s1,string s2,int n,int m)
{
    int dp[n+1][m+1];
    memset(dp,-1,sizeof(dp));
    if(n==0 || m==0)
    return 0;
    if(dp[n][m]!=-1)
    return dp[n][m];
    if(s1[n-1]==s2[m-1])
    return dp[n][m]=1+lic(s1,s2,n-1,m-1);
    else
    return dp[n][m]=max(lic(s1,s2,n-1,m),lic(s1,s2,n,m-1));
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<"max common subsequence->"<<lic(s1,s2,s1.length(),s2.length());
    return 0;
}