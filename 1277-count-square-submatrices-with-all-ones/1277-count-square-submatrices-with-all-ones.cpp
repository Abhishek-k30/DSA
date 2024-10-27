class Solution {
public:
    int n, m;
    int dp[301][301];
    int solve(int i, int j, vector<vector<int>>&matrix){
        if(i>=n || j>=m){
            return 0;
        }
        if(matrix[i][j]==0){
            return 0;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int right = solve(i, j+1, matrix);
        int dg = solve(i+1, j+1, matrix);
        int down = solve(i+1, j, matrix);
        
        return dp[i][j] = 1 + min({right, dg, down});
    }
    int countSquares(vector<vector<int>>& matrix) {
         n = matrix.size();
         m = matrix[0].size();
        
         memset(dp, -1, sizeof(dp));
         int totalSquare = 0;
        
         for(int i = 0; i<n; i++){
             for(int j = 0; j<m; j++){
                 if(matrix[i][j]){
                     totalSquare+= solve(i, j, matrix);
                 }
             }
         }
        
        return totalSquare;
        
    }
};