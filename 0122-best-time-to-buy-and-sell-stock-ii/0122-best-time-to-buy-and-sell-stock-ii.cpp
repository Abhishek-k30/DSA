class Solution {
private:
    int f(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp){
        if(ind==prices.size())
            return 0;
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        
        if(buy){
            return dp[ind][buy] = max(-prices[ind] + f(ind+1, 0, prices, dp), f(ind+1, 1, prices, dp));
        }
        else return dp[ind][buy] = max(prices[ind] + f(ind+1, 1, prices, dp), f(ind+1, 0, prices, dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        return f(0, 1, prices, dp);
    }
};