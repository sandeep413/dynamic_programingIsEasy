#include<iostream>
using namespace std;
int rod_cutting(int len[],int price[],int n)
{
    int dp[n+1][n+1];
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    dp[i][0]=1;
    for(int i=1;i<=n;i++)
    dp[0][i]=0;
    for(int i=1;i<=n;i++)         
    {
        for(int j=1;j<=n;j++)
        {
            if(len[i-1]<=j)
            {
                dp[i][j]=max(price[i-1]+dp[i][j-len[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][n];
}
int main()
{
    int n;
    cout<<"Enter the size of array-";
    cin>>n;
    int len[n];
    cout<<"Enter length of the piece of the rod-";
    for(int i=0;i<n;i++)
    cin>>len[i];
    int price[n];
    cout<<"Enter price of piece-";
    for(int i=0;i<n;i++)
    cin>>price[i];
    cout<<"Maximum profit can be:-"<<rod_cutting(len,price,n);
    return 0;
    return 0;
}
