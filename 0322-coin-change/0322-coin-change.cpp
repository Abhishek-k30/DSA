class Solution {
private:
    int f(int ind, int sum, vector<int> &coins, vector<vector<int>> &dp ){
        if(ind<0){
            if(sum>0)
                return 1e9;
            else return 0;
        }
        
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        
        int notTake = f(ind-1, sum, coins, dp);
        int take = INT_MAX;
        if(coins[ind]<= sum)
            take = 1 + f(ind, sum - coins[ind] , coins, dp);
        
        return dp[ind][sum] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        // int ans =  f(n-1, amount, coins, dp);
        // if(ans>=1e9)
        //     return -1;
        // return ans;
        
        for(int i=1; i<=amount; i++)dp[0][i] = 1e9;
        
        for(int i=1; i<=n; i++){
            for(int j = 0; j<=amount; j++){
                int ans = 1e9;
                ans = min(ans, dp[i-1][j]);
                
                if(coins[i-1]<= j)
                    ans = min(ans, 1+dp[i][j-coins[i-1]]);
                
                dp[i][j] = ans;
            }
        }
        
        if(dp[n][amount]>=1e9)
            return -1;
        return dp[n][amount];
    }
};