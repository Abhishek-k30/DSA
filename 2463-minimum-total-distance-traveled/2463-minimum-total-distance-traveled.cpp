class Solution {
public:
    long long solve(int idx_r, int idx_f, vector<int>& robot, vector<int>& temp,
                   vector<vector<long long>>&dp){
        
        if(idx_r >= robot.size())return 0;
        if(idx_f>=temp.size())return 1e14;
        
        if(dp[idx_r][idx_f]!=-1)return dp[idx_r][idx_f];
        
        
        long long left = abs(robot[idx_r]-temp[idx_f]) +
            solve(idx_r+1, idx_f+1, robot, temp, dp);
        
        
        long long right = solve(idx_r, idx_f+1, robot, temp, dp);
        
        return dp[idx_r][idx_f] = min(left, right);
        
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        sort(robot.begin(),robot.end());
        sort(factory.begin(), factory.end());
        
        vector<int> temp;
        for(auto &it: factory){
            for(int i = 0; i<it[1]; i++){
                temp.push_back(it[0]);
            }
        }
        
        // Recursion + memoization
        //vector<vector<long long>> dp(n, vector<long long>(temp.size(), -1));
        //return solve(0, 0, robot, temp, dp);
        
        
        //Bottom UP
         vector<vector<long long>> dp(n+1, vector<long long>(temp.size()+1, 0));
        
         for(int i = 0; i<n; i++)dp[i][temp.size()] = 1e14;
        
        for(int i = n-1; i>=0; i--){
            for(int j = temp.size()-1; j>=0; j--){
                long long l = abs(robot[i]-temp[j]) + dp[i+1][j+1];
                long long r = dp[i][j+1];
                
                dp[i][j] = min(l, r);
            }
        }
        
        return dp[0][0];
    }
};