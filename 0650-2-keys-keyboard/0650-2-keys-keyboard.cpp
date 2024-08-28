class Solution {
private:
    int solve(int idx, int length, int n, vector<vector<int>> &dp){
        if(idx > n)
            return 1e7;
        if(idx ==  n)
            return 0;
        if(dp[idx][length]!=-1)
            return dp[idx][length];
        
        int copy = 2 + solve(idx+idx, idx, n, dp);
        int paste = 1 + solve(idx+length, length, n, dp);
        
        return dp[idx][length] = min(copy, paste);
    }
public:
    int minSteps(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        if(n == 1)return 0;
        return 1+solve(1,1,n,dp);
    }
};