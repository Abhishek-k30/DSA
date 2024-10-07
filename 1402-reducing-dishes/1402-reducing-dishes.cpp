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
        
        //vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        //return solve(0, 1, satisfaction, dp);
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1e9));
        for(int i = 0; i<=n ; i++)dp[i][0] = 0;
        
        dp[0][1] = satisfaction[0];
        
        for(int i = 1; i<n; i++){
            for(int time = 1; time<=n; time++){
                int include = time * satisfaction[i] + dp[i-1][time-1];
                int exclude = dp[i-1][time];
                
                dp[i][time] = max(include, exclude);
            }
            
        }
        
        int ans = 0;
        
        for(int i = 0; i<=n; i++){
            ans = max(ans, dp[n-1][i]);
        }
        
        return ans;
    }
};