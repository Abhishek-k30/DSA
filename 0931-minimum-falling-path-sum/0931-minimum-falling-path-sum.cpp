class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(matrix);
        
        for(int i = 1; i<n; i++){
            for(int j = 0; j<n; j++){
                int down = 1e9, leftDg = 1e9, rightDg = 1e9;
                if(i-1>=0)down = dp[i-1][j];
                if(i-1>=0 && j-1>=0)leftDg = dp[i-1][j-1];
                if(i-1>=0 && j+1<n)rightDg = dp[i-1][j+1];
                
                dp[i][j] = (dp[i][j]) + min(down, min(leftDg, rightDg) );
            }
        }
        
        int mini = 1e9;
        for(int i = 0; i<n; i++){
            mini = min(mini, dp[n-1][i]);
        }
        
        return mini;
    }
};