class Solution {
public:
    long long solve(int idx, int prev, string &s , vector<vector<long long>>&dp){
        if(idx>=s.size()){
            return 0;
        }
        
        if(dp[idx][prev]!=-1)return dp[idx][prev];
        long long pre = 0, suf = 0;
        
        if(prev!= s[idx]-'0'){
            pre = pre + (idx) + solve(idx+1,s[idx]-'0', s, dp);
            suf = suf + (s.size()-idx) + solve(idx+1, s[idx]-'0', s, dp);
            
            return dp[idx][prev] = min(pre, suf);
        }
        else {
            return dp[idx][prev] = solve(idx+1, prev, s, dp);
        }
    }
    long long minimumCost(string s) {
        int n = s.size();
        vector<vector<long long>> dp1(n+1, vector<long long>(2, -1));
        vector<vector<long long>> dp2(n+1, vector<long long>(2, -1));
        return min(solve(0, 0, s, dp1), solve(0,1, s, dp2));
    }
};