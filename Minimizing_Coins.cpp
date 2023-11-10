#include <bits/stdc++.h>
using namespace std;

// Recursive Code Giving TLE on 8 test Cases; 
int MinCoinsRec(vector<int> &coins, int n, int x)
{
    if (x == 0)
        return 0;
    int ans = 1e9; 
    for (int i = 0; i < n; i++){
        if(coins[i] <= x)
                ans =  min(ans, MinCoinsRec(coins, n, x - coins[i])+1); 
    }
    return ans; 
}

//Recursion + Memoization Giving TLE on 2 Test Case 
int MinCoinsMemo(vector<int> &coins, int n, int x,  vector<int>&dp)
{
    if (x == 0)
        return 0;
    
    if(dp[x] != 1e9)return dp[x]; 
    int ans = 1e9; 
    for (int i = 0; i < n; i++){
        if(coins[i] <= x)
                ans =  min(ans, MinCoinsMemo(coins, n, x - coins[i],dp)+1); 
    }
    dp[x] = ans; 
    return dp[x]; 
}

// Tabulation  ACCEPTED 
int MinCoinsTab(vector<int> &coins, int n, int x,  vector<int>&dp){

    // Base Case 
    dp[0] = 0; 

    //dp[i] = min coins to generate a sum of i
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(coins[j] <= i){
                // transition
                dp[i] =  min(dp[i], dp[i - coins[j]]+1); 
            }
        }
    }
    return dp[x]; 
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
    // Recursive 
    // int ans = MinCoinsRec(coins, n, x);
    // Rec + Mem; 
    vector<int>dp(x + 1 , 1e9);  
    // int ans = MinCoinsMemo(coins, n, x,dp);
    // Tabulation  
    int ans = MinCoinsTab(coins, n, x,dp); 
    
    if(ans < 1e9)cout<<ans<<endl; 
    else cout<<-1<<endl; 
    return 0;
}