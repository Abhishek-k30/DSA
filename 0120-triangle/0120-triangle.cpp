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
        
        vector<vector<int>> dp(triangle);
        //return f(0, 0, n, triangle, dp);
        
        for(int i = n-2; i>=0; i--){
            for(int j =i; j>=0 ; j-- ){
                int down = dp[i][j] + dp[i+1][j];
                int dg = dp[i][j] + dp[i+1][j+1];
                
                dp[i][j] = min(down, dg);
            }
        }
        
        return dp[0][0];
    }
};