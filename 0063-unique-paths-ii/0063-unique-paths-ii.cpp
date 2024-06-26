class Solution {
private:
    int f(int i , int j , vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp){
        if(i>=0 && j>=0  && obstacleGrid[i][j]==1)
            return 0;
        if(i<0 || j<0)
            return 0;
        if(i==0 && j==0)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j] = f(i-1, j, obstacleGrid, dp) + f(i, j-1, obstacleGrid, dp);
    } 
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        //return f(n-1, m-1, obstacleGrid, dp);
        
        for(int i=0; i<n ; i++){
            for(int j=0; j<m; j++){
                if(obstacleGrid[i][j]==1)
                    dp[i][j] = 0;
                else if(i==0 && j==0)
                    dp[i][j] = 1;
                else{
                    int down = 0, right = 0;
                    if(i>0)down = dp[i-1][j];
                    if(j>0)right = dp[i][j-1];
                    
                    dp[i][j] = down + right;
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};