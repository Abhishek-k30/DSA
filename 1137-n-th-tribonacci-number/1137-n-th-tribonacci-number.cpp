class Solution {
public:
    int f(int n, vector<int> &dp){
        if(n==0)return dp[n]=0;;
        if(n==1 || n==2)return dp[n]=1;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=f(n-3,dp)+f(n-1, dp)+f(n-2, dp);
    }
    int tribonacci(int n) {
       // int dp[3]={0,1,1};
       //  for(int i=3; i<=n; i++){
       //      dp[i%3]+=(dp[(i+1)%3]+dp[(i+2)%3]);
       //  }
       //  return dp[n%3];
        vector<int> dp(n+5, -1);
        return f(n, dp);
    }
};