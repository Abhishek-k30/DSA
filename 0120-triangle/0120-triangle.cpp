class Solution {
private:
    int f(int i , int j , int n,  vector<vector<int>>& tri , vector<vector<int>> &dp){
        
        if(i==n-1)
            return tri[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int down = tri[i][j] + f(i+1, j , n, tri, dp);
        
        int dg = tri[i][j] + f(i+1, j+1, n, tri, dp);
        
        return dp[i][j] = min(down, dg);
        
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, 0, n, triangle, dp);
    }
};