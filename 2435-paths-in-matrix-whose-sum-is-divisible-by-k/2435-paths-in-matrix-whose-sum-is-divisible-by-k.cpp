class Solution {
public:
    const int mod = 1e9+7;
    int solve(int i , int j, int n, int m, int k, int sum, vector<vector<int>> &grid,
             vector<vector<vector<int>>> &dp){
        if(i==n || j== m)return 0;
        if(i== n-1 && j== m-1)return ((sum + grid[i][j])%k) == 0;
        if(dp[i][j][sum]!=-1)return dp[i][j][sum];
        
        return dp[i][j][sum] = (solve(i+1, j, n, m, k, (sum+ grid[i][j])%k, grid, dp)
            + solve(i, j+1, n, m, k, (sum + grid[i][j])%k, grid, dp))%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1, vector<int>(k+1, -1)));
        return solve(0,0,n, m,k, 0, grid, dp);
        
    }
};