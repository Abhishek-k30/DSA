class Solution {
private:
    int n , m;
    vector<int> dr = {1,0,-1,0};
    vector<int> dc = {0,1,0,-1};
    int dfs(int row, int col, vector<vector<int>>&mat, vector<vector<int>>&dp){
        if(dp[row][col]!=-1)return dp[row][col];
        
        int maxi = 1;
        
        for(int k = 0; k<4; k++){
            int nrow = row + dr[k];
            int ncol = col + dc[k];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
              mat[nrow][ncol] > mat[row][col]){
                maxi = max(maxi, 1 + dfs(nrow, ncol, mat, dp));
            }
        }
        
        return dp[row][col] = maxi;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
          n = matrix.size();
          m = matrix[0].size();
         
          vector<vector<int>> dp(n, vector<int>(m, -1));
          int ans = 1;
          for(int i = 0; i<n; i++){
              for(int j = 0; j<m; j++){
                  ans = max(ans, dfs(i, j, matrix, dp));
              }
          }
          
        return ans;
        
    }
};