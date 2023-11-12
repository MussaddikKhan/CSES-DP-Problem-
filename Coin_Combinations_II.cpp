
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
// Recursion Gives TLE For 9 Test Case;
int unique_combinations(vector<int> &coins, int i, int x)
{

    if (x == 0)
        return 1;
    if (i >= coins.size() || x < 0)
        return 0;
    int pick = unique_combinations(coins, i, x - coins[i]);
    int skip = unique_combinations(coins, i + 1, x);

    return (pick + skip) % MOD;
}

// Rec + Memo  TLE on 6 Test Cases
int unique_combinationsMem(vector<int> &coins, int i, int x, vector<vector<int>> &dp)
{

    if (x == 0)
        return 1;
    if (i >= coins.size() || x < 0)
        return 0;
    if (dp[i][x] != -1)
        return dp[i][x];
    int pick = unique_combinationsMem(coins, i, x - coins[i], dp);
    int skip = unique_combinationsMem(coins, i + 1, x, dp);

    dp[i][x] = (pick + skip) % MOD;
    return dp[i][x];
}
// Iterative And Tabulation ACCEPTED 
int unique_combinationsTab(vector<int> &coins, int n, int x)
{
    vector<vector<int>> dp(n + 5, vector<int>(x + 5));

    // dp[i][k] = number of ways to construct sum k
    //  such that all coins before coin[i] are unusable
    // Base Case
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int sum = 1; sum <= x; sum++)
        {
            int skip = dp[i + 1][sum];
            int pick = 0;
            if (sum - coins[i] >= 0)
            {
                pick = dp[i][sum - coins[i]];
            }

            dp[i][sum] = (pick + skip) % MOD;
        }
    }
    return dp[0][x] % MOD; // Actual Sub Problem
}
int main()
{

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int ans = 0;
    int i = 0;
    ans = unique_combinationsTab(coins, n, x);
    cout << ans << endl;

    return 0;
}