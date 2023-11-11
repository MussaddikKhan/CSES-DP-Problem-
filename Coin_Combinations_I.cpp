
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
// Recursvie Solution  Gives TLE on 6 test Case 
int TotalCoinsCombinationRec(vector<int>&coins,  int x){

    if(x == 0)return 1; 

    int ans = 0; 
    for(int i = 0; i < coins.size(); i++){
        if(coins[i] <= x){
            ans += TotalCoinsCombinationRec(coins, x - coins[i]); 
        }
    }
    return ans; 
}

// Rec + Memoization  ACCEPTED 

int TotalCoinsCombinationMem(vector<int>&coins,  int x,  vector<int>&dp){

    if(x == 0)return 1; 

    if(dp[x] !=  -1)return dp[x]; 

    int ans = 0; 
    for(int i = 0; i < coins.size(); i++){
        if(coins[i] <= x){
            ans = (ans + TotalCoinsCombinationMem(coins, x - coins[i],dp))%MOD; 
        }
    }
    dp[x] =  ans; 
    return dp[x]%MOD; 
}

// Tabulation / Iterative ACCEPTED  
int TotalCoinsCombinationTab(vector<int>&coins,  int x){
     vector<int>dp(x+1, 0);
        dp[0] = 1; 
        for(int  i = 1; i <= x; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i >= coins[j])
                  dp[i] = (dp[i]  + dp[i - coins[j]])%MOD; 
            }
        }
        return dp[x]; // --> Final Sub Problem...
}

int main()
{

     int n, x; 
     cin >> n >> x ; 

    vector<int>coins(n); 
    for(int i = 0; i < n; i++){
       cin >> coins[i]; 
    }
    int ans = 0; 
    //  Solve Recursion 
    //  ans = TotalCoinsCombinationRec(coins, x);
    vector<int>dp(x+1, -1); 
    // Rec + Mem
    // ans = TotalCoinsCombinationMem(coins, x, dp); 

    // Tabulation 
    ans = TotalCoinsCombinationTab(coins, x); 
    cout<<ans<<endl;  
    return 0;
}