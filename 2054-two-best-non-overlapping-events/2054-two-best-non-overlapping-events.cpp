class Solution {
private:
    int nextIndex(int l, int tar , vector<vector<int>>&arr){
        int r = arr.size()-1;
        
        int index = r+1;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(arr[mid][0]>tar){
                index = mid;
                r = mid-1;
            }
            else l = mid + 1;
        }
        
        return index;
    }
public:
    int solve(int idx, int d, vector<vector<int>>& events, vector<vector<int>>&dp){
        if(idx>=events.size()){
            return 0;
        }
        
        if(d<=0){
            return 0;
        }
        
        if(dp[idx][d]!=-1)return dp[idx][d];
        int take = 0, notTake = 0;
        int nextIdx = nextIndex(idx, events[idx][1], events);
        take = events[idx][2] + solve(nextIdx, d-1, events, dp);
        notTake = (solve(idx+1, d, events, dp));
        
        return dp[idx][d] = max(take, notTake);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        
        sort(events.begin(), events.end(), [&](vector<int>&a, vector<int>&b){
            return a[0]<b[0];
        });
        
        
        vector<vector<int>> dp(n, vector<int>(3, -1));
        
        return solve(0, 2, events, dp);
    }
};