class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int p1=0, p2=0,p3=0;
        for(int i = 1; i<n; i++){
            int twoMulti = dp[p1]*2;
            int threeMulti = dp[p2]*3;
            int fiveMulti = dp[p3]*5;
            
            dp[i] = min({twoMulti, threeMulti, fiveMulti});
            
            if(dp[i] == twoMulti)p1++;
            if(dp[i] == threeMulti)p2++;
            if(dp[i] == fiveMulti)p3++;
        }
        
        return dp[n-1];
    }
};