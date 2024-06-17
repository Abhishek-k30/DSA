class Solution {
private:
    int f(int ind, int amount, vector<int> &coins, vector<vector<int>>&dp){
        if(amount==0)return 1;
        if(ind<0)
            return 0;
        
        if(dp[ind][amount]!=-1)
            return dp[ind][amount];
        
        int notTake = f(ind-1, amount, coins, dp);
        int take = 0;
        if(coins[ind]<=amount)
            take = f(ind, amount-coins[ind], coins, dp);
        
        return dp[ind][amount] = take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        
        //return f(n-1, amount, coins, dp);
        
       // for(int i= 0; i<n; i++)dp[i][0] = 1;
        
        dp[0][0] = 1;
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<=amount; j++){
                int notTake = dp[i-1][j];
                int take = 0;
                if(coins[i-1]<=j)
                    take = dp[i][j-coins[i-1]];
                
                dp[i][j] = take + notTake;
            }
        }
        
        return dp[n][amount];
    }
};