#include<iostream>
#include<climits>
using namespace std;
int subsetsumdiff(int arr[],int n,int range)
{
    bool dp[n+1][range+1];
    dp[0][0]=true;
    for(int i=0;i<=n;i++)
      dp[i][0]=true;
    for(int i=0;i<=range;i++)
      dp[0][i]=false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=range;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    int diff=INT_MAX;
    for(int i=0;i<=range/2;i++)
    {
        if(dp[n][i]==true)
        {
            diff= min(diff,range-2*i);
        }
    }
    return diff;

}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
     cin>>arr[i];
    int range;
    for(int i=0;i<n;i++)
     range+=arr[i];
    cout<<"Minimum diff is :- "<<subsetsumdiff(arr,n,range);
    return 0;
}