class Solution {
public:
    int n, m;
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp){
        if( j<0 || j>=m || grid[i][j]==0){
             return -1;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int res = 0;
        
        if(i+1<n && grid[i+1][j]==1){
            res = 1 + min({solve(i+1, j-1, grid, dp) , solve(i+1,j+1, grid, dp)});
        }
        
        return dp[i][j] = res;
    }
    int countPyramids(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for(int i = 0; i<n-1; i++){
            for(int j = 0; j<m-1; j++){
                if(grid[i][j]){
                    ans+=solve(i, j, grid, dp);
                }
            }
        }
        
        
        reverse(grid.begin(), grid.end());
        dp = vector<vector<int>>(n, vector<int>(m, -1));
         for(int i = 0; i<n-1; i++){
            for(int j = 0; j<m-1; j++){
                if(grid[i][j]){
                    ans+=solve(i, j, grid, dp);
                }
            }
        }
        return ans;
    }
};