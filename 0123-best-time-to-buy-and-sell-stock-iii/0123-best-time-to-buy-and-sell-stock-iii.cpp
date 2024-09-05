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
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>                 (cap+1,-1)));
        
        return solve(0,1,cap,prices,dp);
    }
};