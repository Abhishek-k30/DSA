class Solution {
private:
    int solve(int num, vector<int>&dp){
        if(num<=1)return 1;
        if(dp[num]!=-1)return dp[num];
        
         int ans = 0;
        for(int i= 1; i<=num ; i++){
            ans+= solve(i-1, dp)*solve(num-i, dp);
        }
        
        return dp[num] = ans;
        
    }
public:
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};