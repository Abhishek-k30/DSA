class Solution {
public:
    int f(int i, int j , vector<vector<int>>& Grid, vector<vector<int>> &dp){
        int n=Grid.size();
        int m=Grid[0].size();
        
        // Base Case
        if(i<0 ||i>=n || j<0 || j>=m)return 0;
        if(Grid[i][j]==1)return 0;
        if(i==n-1 && j==m-1) return 1;
            
            
        
        
        
        
        // Memoization
        if(dp[i][j]!=-1)return dp[i][j];
        
        
        // Right movement
        int right=f(i, j+1, Grid, dp);
        
        // Down movement
        int down=f(i+1,j, Grid, dp);
        
        
        // total sum of movement
        return dp[i][j]=right+down;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        return f(0,0,obstacleGrid, dp);
    }
};