class Solution {
public:
    int f(int i, int j, vector<vector<int>> & triangle, vector<vector<int>> &dp){
        int n=triangle.size();
        
        // Base Case
        if(i==n-1)return triangle[i][j];
        
        // Memoization
        if(dp[i][j]!=-1)return dp[i][j];
        
        // Diagonal Movement
        int dg=triangle[i][j]+f(i+1, j+1, triangle, dp);
        
        // Down Movement
        int down=triangle[i][j]+f(i+1, j, triangle, dp);
        
        // Minimum of diagnal and down movement
        
        return dp[i][j]=min(dg, down);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0,0, triangle, dp);
    }
};