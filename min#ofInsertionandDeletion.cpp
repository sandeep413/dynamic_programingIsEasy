#include<bits/stdc++.h>
using namespace std;
pair<int,int>minInsertDelete(string s1,string s2,int a,int b)
{
    int dp[b+1][a+1];
    for(int i=0;i<=b;i++)
    {
        for(int j=0;j<=a;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=a;j++)
        {
            if(s1[i-1]==s2[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    pair<int,int>p;
    p.first=a-dp[b][a];
    p.second=b-dp[b][a];
    return p;
}
int main()
{
  string s1,s2;
  cout<<"Enter both the string\n";
  cin>>s1>>s2;
  pair<int,int>p=minInsertDelete(s1,s2,s1.length(),s2.length());
  cout<<"Min # of inertion:-"<<p.first<<endl;
  cout<<"Deletion is:-"<<p.second;
    return 0;
}
