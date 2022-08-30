#include<iostream>
#include<climits>
using namespace std;
int minCoins(int arr[],int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=1;i<=n;i++)
    dp[i][0]=0;
    for(int i=1;i<=sum;i++)
    dp[0][i]=INT_MAX-1;
    dp[0][0]=INT_MAX-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(i==1)
            {
                if(j%arr[0]==0)
                {
                    dp[i][j]=j/arr[0];
                }
                else
                dp[i][j]=INT_MAX-1;
            }
            if(arr[i-1]<=j)
            {
                dp[i][j]=min(dp[i][j-arr[i-1]]+1,dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
    
}
int main()
{
    int n;
    cout<<"Number of coins\n";
    cin>>n;
    int coins[n];
    cout<<"Show available coins\n";
    for(int i=0;i<n;i++)
    cin>>coins[i];
    int sum;
    cout<<"Enter sum which you want to make\n";
    cin>>sum;
    cout<<"Min number of coins are - "<<minCoins(coins,n,sum);return 0;
}