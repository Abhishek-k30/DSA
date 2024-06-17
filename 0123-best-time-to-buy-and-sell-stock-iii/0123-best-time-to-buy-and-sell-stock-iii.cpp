class Solution {
private:
    int f(int ind, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(ind==prices.size() || cap==0)
            return 0;
        
        if(dp[ind][buy][cap]!=-1)
            return dp[ind][buy][cap];
        
        if(buy){
            return dp[ind][buy][cap] = max(-prices[ind] + f(ind+1, 0, cap, prices, dp), 
                                          f(ind+1, 1, cap, prices, dp));
        }
        else{
            return dp[ind][buy][cap] = max(prices[ind] + f(ind+1, 1, cap-1, prices, dp) ,
                                          f(ind+1, 0, cap, prices, dp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        
        return f(0, 1, k, prices, dp);
        
    }
};