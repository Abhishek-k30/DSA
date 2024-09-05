class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1,0));
        for(int i = 1; i<=amount; i++)dp[0][i] = 1e9;
        
        for(int i = 1; i<=n; i++){
            for(int j = 0; j<=amount; j++){
                 int notTake = dp[i-1][j];
                 int take = 1e9;
                 if(coins[i-1]<=j){
                     take = 1+dp[i][j-coins[i-1]];
                 }
                
                dp[i][j] = min(take, notTake);
                
            }
        }
        int ans = dp[n][amount];
        if(ans==1e9)return -1;
        return ans;
    }
};