class Solution {
public:
    int solve(int idx, int time, vector<int>& sat, vector<vector<int>>&dp){
        if(idx>=sat.size()){
            return 0;
        }
        
        if(dp[idx][time]!=-1)return dp[idx][time];
        int take = time* sat[idx] + solve(idx+1, time+1, sat, dp);
        int notTake = solve(idx+1,time, sat, dp);
        
        return dp[idx][time] = max(take, notTake);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, 1, satisfaction, dp);
        
    }
};