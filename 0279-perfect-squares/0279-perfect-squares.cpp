class Solution {
public:
    int solve(int n, vector<int>&dp){
        
        if(n<0){
            return INT_MAX;
        }
        if(n==0){
            return 0;
        }
        
        if(dp[n]!=-1)return dp[n];
        
        int minCount = INT_MAX;
        for(int i = 1; i*i<=n; i++){
            int res = 1 + solve(n-i*i, dp);
            minCount = min(minCount, res);
        }
        
        return dp[n] = minCount;
    }
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};