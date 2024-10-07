class Solution {
public:
    int solve(int cur_idx, int prev, string &s, vector<vector<int>> &dp){
        if(cur_idx>=s.size()){
            return 0;
        }
        
        if(dp[cur_idx][prev]!=-1)return dp[cur_idx][prev];
        int flip = INT_MAX, notFlip = INT_MAX;
        
        if(s[cur_idx] == '0'){
            if(prev == 0){
                flip = 1 + solve(cur_idx+1, 1, s, dp);
                notFlip = solve(cur_idx+1, 0, s, dp);
            }
            else{
                flip = 1 + solve(cur_idx+1, 1, s, dp);
            }
        }
        else{
            if(prev == 0){
                flip = 1 + solve(cur_idx+1, 0, s, dp);
                notFlip = solve(cur_idx+1, 1, s, dp);
            }
            else{
                notFlip = solve(cur_idx+1, 1, s, dp);
            }
        }
        
        return dp[cur_idx][prev] = min(flip, notFlip);
    }
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(0, 0, s, dp);
        
    }
};