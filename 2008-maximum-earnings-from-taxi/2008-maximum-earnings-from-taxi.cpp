#define ll long long
class Solution {
private:
    int nextIndex(int l, int tar, vector<vector<int>>&arr){
        int r = arr.size()-1;
        
        int index = r+1;
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(arr[mid][0]>= tar){
                index = mid;
                r = mid-1;
            }
            else l = mid + 1;
        }
        
        return index;
    }
public:
    ll solve(int idx, int n, vector<vector<int>>&rides, vector<ll>&dp){
        if(idx>=n){
            return 0;
        }
        
        
        if(dp[idx]!=-1)return dp[idx];
        ll take = 0, notTake = 0;
        
        int nextIdx = nextIndex(idx, rides[idx][1], rides);
        
        take = (rides[idx][1]-rides[idx][0]+rides[idx][2]) + solve(nextIdx,n, rides, dp);
        notTake = (solve(idx+1, n, rides, dp));
        
        return dp[idx] = max(take, notTake);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int nn = rides.size();
        
        sort(rides.begin(), rides.end(),[&](vector<int>&a, vector<int>&b){
            return a[0]<=b[0];
        });
        
        vector<ll> dp(nn+1, -1);
        
        return solve(0, nn, rides, dp);
        
        
    }
};