class Solution {
private:
    int solve(int ind, int buy, int cap, vector<int>&prices, vector<vector<vector<int>>>&dp){
        if(ind == prices.size() || cap == 0)
            return 0;
        if(dp[ind][buy][cap]!=-1)
            return dp[ind][buy][cap];
        
        int profit =0;
        
        if(buy){
            profit = max(-prices[ind] + solve(ind+1, 0, cap, prices, dp),
                        solve(ind+1,1,cap,prices, dp));
        }
        else {
            profit = max(prices[ind] + solve(ind+1,1, cap-1, prices, dp),
                        solve(ind+1,0,cap,prices,dp));
        }
        
        return dp[ind][buy][cap] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cap = 2;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>                 (cap+1,0)));
        
        //return solve(0,1,cap,prices,dp);
        
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<=1; j++){
                for(int k = cap;k>=1; k--){
                    if(j == 1){
                        dp[i][j][k] = max(-prices[i] + dp[i+1][0][k],
                                         dp[i+1][1][k]);
                    }
                    else {
                        dp[i][j][k] = max(prices[i] + dp[i+1][1][k-1],
                                         dp[i+1][0][k]);
                    }
                }
            }
        }
        return dp[0][1][cap];
    }
};