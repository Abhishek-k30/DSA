class Solution {
private:
    int helper(int i, int j, int n, int m ,vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>> &dp){
        if(i == n-1)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        
        int  mini = INT_MAX;
        for(int k = 0; k<m; k++){
            int cur = grid[i][j] + moveCost[grid[i][j]][k] + helper(i+1,k, n, m, grid, moveCost, dp);
            mini = min(mini, cur);
        }
        return dp[i][j] = mini;
    }
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int ans = INT_MAX;
        
        for(int i = 0; i<m; i++){
            ans = min(ans, helper(0, i, n, m, grid, moveCost, dp ));
        }
         
        return ans;
        
    }
};