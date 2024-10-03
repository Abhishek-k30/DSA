class Solution {
private:
    int nextIndex(int l, int tar, vector<vector<int>>&arr){
        int r = arr.size()-1;
        int index = r+1;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(arr[mid][0]>tar){
                index = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        
        return index;
    }
public:
    int solve(int idx, int k, vector<vector<int>> &e, vector<vector<int>>&dp){
        if(idx>=e.size()){
            return 0;
        }
        
        if(k<=0){
            return 0;
        }
        
        if(dp[idx][k]!=-1){
            return dp[idx][k];
        }
        
        int take = 0, notTake = 0;
        
        int nextIdx = nextIndex(idx, e[idx][1], e);
        
        take = e[idx][2] + solve(nextIdx, k-1, e, dp);
        notTake = solve(idx+1, k, e, dp);
        
        return dp[idx][k] = max(take, notTake);
    }
    int maxValue(vector<vector<int>>& e, int k) {
        int n = e.size();
        
        sort(e.begin(), e.end());
        
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        
        return solve(0, k, e, dp);
    }
};