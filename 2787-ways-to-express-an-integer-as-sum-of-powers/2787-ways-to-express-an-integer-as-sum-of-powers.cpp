class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[301][301];
    int solve(int idx, int n, int x){
        if(n<0){
            return 0;
        }
        
        if(n==0){
            return 1;
        }
        
        
        if(pow(idx, x)>n)return 0;
        
        if(dp[idx][n]!=-1)return dp[idx][n];
        int take = 0, notTake = 0;
        
        take = solve(idx+1, n-pow(idx, x), x);
        notTake = solve(idx+1, n, x);
        
        return dp[idx][n] = ((take%mod) + (notTake%mod))%mod;
    }
    int numberOfWays(int n, int x) {
        
        memset(dp, -1, sizeof(dp));
        return solve(1,n, x);
    }
};