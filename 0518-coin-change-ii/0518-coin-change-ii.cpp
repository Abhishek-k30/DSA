class Solution {
public:
    int f(int ind, int tar, vector<int> &coins, vector<vector<int>> &dp){
        int n=coins.size();
        
        //Base Case
        if(ind<0 || ind>=n)return 0;
        if(ind==n-1)return (tar%coins[ind]==0);
        
        // Memoization
        if(dp[ind][tar]!=-1)return dp[ind][tar];
        
        // Not Pick
        int notPick=f(ind+1, tar, coins, dp);
        
        // Pick
        int Pick=0;
        if(tar-coins[ind]>=0){
            Pick=f(ind,tar-coins[ind], coins, dp);
        }
        
        // Return sum
        return dp[ind][tar]=notPick+Pick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return f(0, amount, coins, dp);
    }
};

// TC=O(N*AMOUNT), SC=O(N*AMOUNT)+O(AMOUNT);
