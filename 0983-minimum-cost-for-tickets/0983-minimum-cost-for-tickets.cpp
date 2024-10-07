class Solution {
private:
    int index(int cur_idx, int dur, vector<int>&days){
        int val = days[cur_idx] + dur-1;
        
        int l = cur_idx, r = days.size()-1;
        int ans = days.size();
        
        while(l<=r){
            int mid = l + (r-l)/2;
            if(days[mid]>val){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        
        return ans;
    }
public:
    int solve(int idx, vector<int>&days, vector<int>&costs, vector<int>&dp){
        if(idx>=days.size()){
            return 0;
        }
        
        if(dp[idx]!=-1)return dp[idx];
        int oneDay = 1e9, weekDay = 1e9, monthDay = 1e9;
        
        oneDay = costs[0] + solve(idx+1, days, costs, dp);
        weekDay = costs[1] + solve(index(idx, 7, days), days, costs, dp);
        monthDay = costs[2] + solve(index(idx, 30, days), days, costs, dp);
        
        return dp[idx] = min({oneDay, weekDay, monthDay});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        vector<int> dp(n+1, -1);
        return solve(0, days, costs, dp);
    }
};