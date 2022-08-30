#include <iostream>
using namespace std;
bool target(int arr[], int n, int w)
{
    bool dp[n + 1][w + 1];
 
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 1; i <= w; i++)
    {
        dp[0][i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=w; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j - arr[i - 1]]) || (dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][w];
}
int main()
{
    int sum, n;
    cin >> n >> sum;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << target(arr, n, sum);
    return 0;
}