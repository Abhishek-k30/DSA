class Solution {
private:
    int solve(int ind, int buy, vector<int>&prices, vector<vector<int>>&dp){
        if(ind == prices.size())
            return 0;
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        
         int profit = 0;
        
        // if buy == 1 means we need to buy the stocks
        // else if buy == 0 means we have already buyed stock, we now need to sell it
        
        if(buy){
            profit = max(-prices[ind] + solve(ind+1,0,prices, dp) ,
                        solve(ind+1,1, prices, dp));
        }
        else {
            profit = max(prices[ind] + solve(ind+1,1,prices,dp) ,
                         solve(ind+1,0,prices,dp));
        }
        
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        //return solve(0, 1, prices, dp);
        
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<=1; j++){
                if(j == 1){
                    dp[i][j] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
                }
                else dp[i][j] = max(prices[i] + dp[i+1][1], dp[i+1][0]);
            }
        }
        return dp[0][1];
    }
};