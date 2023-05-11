class Solution {
public:
    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        int n=grid.size();
        int m=grid[0].size();
        
        // Base Case
        if(i<0 || i>=n || j<0 || j>=m)return 1e5;
        if(i==n-1 && j==m-1)return grid[i][j];
        
        // Memoization
        if(dp[i][j]!=-1)return dp[i][j];
        
        // Right movement
        int right=grid[i][j]+f(i, j+1, grid, dp);
        
        //Down movement
        int down=grid[i][j]+f(i+1, j, grid, dp);
        
        // Returning minimum of the left and right movement
        return dp[i][j]=min(right, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        return f(0,0,grid, dp);
        
    }
};