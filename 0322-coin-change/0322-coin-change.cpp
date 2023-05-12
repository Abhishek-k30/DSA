class Solution {
public:
    int f(int ind, int tar, vector<int>& coins , vector<vector<int>> &dp ){
        int n=coins.size();
        
        // Base Case
        if(ind<0 || ind>=n)return 1e9;
        if(ind==n-1){
            if(tar% coins[ind]==0)return tar/coins[ind];
            return 1e9;
        }
        
        // Memoization
        if(dp[ind][tar]!=-1)return dp[ind][tar];
        
        // Not Pick
        int notPick= f(ind+1, tar,coins , dp);
        
        // Pick
        int Pick=INT_MAX;
        if(tar-coins[ind]>=0){
            Pick=1+f(ind, tar-coins[ind], coins, dp);
        }
        
        // Returning Minimum
        return dp[ind][tar]=min(Pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1,-1));
        int ans=f(0, amount, coins , dp);
        if(ans>=1e9)return -1;
        return ans;
    }
};