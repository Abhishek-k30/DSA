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
        // vector<int> dp(n+1, -1);
        // return solve(0, days, costs, dp);
        
        int maxi = days.back();
        vector<int> dp(maxi+1,0);
        
        set<int> st(days.begin(), days.end());
        
        for(int i = 1; i<=maxi; i++){
            if(st.find(i)==st.end()){
                dp[i] = dp[i-1];
                continue;
            }
            
            int one = 1e9, week = 1e9, month = 1e9;
            
            if(i-1>=0)one = costs[0] + dp[i-1];
            else one = costs[0];
            if(i-7>=0)week = costs[1] + dp[i-7];
            else week = costs[1];
            if(i-30>=0)month = costs[2] + dp[i-30];
            else month = costs[2];
            
            dp[i] = min({  one, week, month});
        }
        
        return dp[maxi];
    }
};