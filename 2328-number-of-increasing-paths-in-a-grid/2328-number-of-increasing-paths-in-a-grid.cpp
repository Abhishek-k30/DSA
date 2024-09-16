class Solution {
public:
    const int mod = 1e9+7;
    int n, m;
    vector<int> dr = {0,-1,0,1};
    vector<int> dc = {1,0,-1,0};
    long solve(int i, int j, vector<vector<long>>&dp, vector<vector<int>>&grid){
        if(dp[i][j]!=-1)return dp[i][j];
        
        int result = 1;
        for(int k = 0; k<4; k++){
                    int nrow = i + dr[k];
                    int ncol = j + dc[k];
                    
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
              grid[nrow][ncol]>grid[i][j]){
              result = (result+ solve(nrow,ncol, dp, grid))%mod;
          }
        }
        
        return dp[i][j] = result;
        
    }
    int countPaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<long>> dp(n, vector<long>(m, -1));
        
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
               ans = (ans+solve(i,j, dp, grid) )%mod;
            }
        }
        
        return ans;
        
    }
};