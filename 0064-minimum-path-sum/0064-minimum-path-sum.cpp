class Solution {
private:
    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i<0 || j<0)
            return INT_MAX;
        if(i==0 && j==0)
            return grid[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j] = grid[i][j] +   min(f(i-1, j, grid, dp) , f(i, j-1, grid, dp));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                }
                else{
                    int left = INT_MAX, up = INT_MAX;
                    if(i-1>=0)left = grid[i][j] + dp[i-1][j];
                    if(j-1>=0)up = grid[i][j] + dp[i][j-1];
                    
                    dp[i][j] = min(left, up);
                }
                
            }
        }
        
        return dp[n-1][m-1];
    }
};