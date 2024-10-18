class Solution {
public:
    int solve(int idx, int n, string s, vector<int>&dp){
        if(idx>=n){
            return 1;
        }
        
        
        if(dp[idx]!=-1)return dp[idx];
        
        
        int take_one_char = 0;
        
        if(stoi(s.substr(idx, 1))>0)take_one_char = solve(idx+1, n, s, dp);
        
        int take_two_char = 0;
        
        if(idx<n-1 && stoi(s.substr(idx, 2))>9  && stoi(s.substr(idx, 2))<=26){
            take_two_char = solve(idx+2, n, s, dp);
        }
        
        return dp[idx] = take_one_char + take_two_char;
    }
    int numDecodings(string s) {
        int n = s.size();
        
        vector<int> dp(n, -1);
        return solve(0, n, s, dp);
    }
};