#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(string str, int i, int j)
{
    while (i <= j)
    {
        if (str[i] != str[j])
            return false;
        else
        {
            i++;
            j--;
        }
    }
    return true;
}
int palindrome(string str, int i, int j)
{
    if (ispalindrome(str, 0, str.length() - 1))
        return 0;
    if (i >= j)
        return 0;
    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = palindrome(str, i, k) + palindrome(str, k + 1, j) + 1;
        ans = min(ans, temp);
    }
    return ans;
}
int main()
{
    string str;
    cin >> str;
    cout << palindrome(str, 0, str.length() - 1);
    return 0;
}