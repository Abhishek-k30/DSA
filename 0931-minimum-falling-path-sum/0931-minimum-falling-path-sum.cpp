class Solution {
private:
    int f(int i, int j ,  int n , vector<vector<int>>& mat, vector<vector<int>> &dp){
        
        if(j<0 || j>=n)
            return 1e9;
        if(i==n-1)
            return mat[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        
        int dl = mat[i][j] + f(i+1, j-1, n, mat, dp);
        int dr = mat[i][j] + f(i+1, j+1, n, mat, dp);
        
        int dw = mat[i][j] + f(i+1, j , n, mat, dp);
        
        return dp[i][j] = min({dl, dr, dw});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        vector<vector<int>> dp (matrix);
        
         int minSum = 1e9;
        
//         for(int i=0; i<n; i++){
//             minSum = min(minSum , f(0, i, n, matrix, dp));
//         }
        
//         return minSum;
        
        for(int i = n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int dl = 1e9, dr = 1e9;
                if(j>0) dl = dp[i][j] + dp[i+1][j-1];
                if(j<n-1)dr = dp[i][j] + dp[i+1][j+1];
                int dw = dp[i][j] + dp[i+1][j];
                
                dp[i][j] = min({dl, dr, dw});
            }
        }
        
        
        
        for(int i = 0; i<n; i++){
            minSum = min(minSum , dp[0][i]);
        }
        
        return minSum;
    }
};