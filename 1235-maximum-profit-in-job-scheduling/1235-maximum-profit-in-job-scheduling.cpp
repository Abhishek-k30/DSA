class Solution {
private:
    int nextIndex(int tar, vector<vector<int>> &arr){
        int l = 0, r = arr.size()-1;
          
        int idx = arr.size();
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(arr[mid][0]>= tar){
                idx =  mid;
                r = mid-1;
            }
            else l = mid+1;
        }
            
        return idx;
    }
     
public:
    int n;
    int solve(int idx, vector<vector<int>> &arr, vector<int>&memo){
        if(idx >= arr.size()){
            return 0;
        }
        
        if(memo[idx]!=-1)return memo[idx];
        
        int nextIdx = nextIndex(arr[idx][1], arr);
        
        int take = arr[idx][2] + solve(nextIdx, arr, memo);
        int notTake = solve(idx+1, arr, memo);
        
        return memo[idx] = max(take, notTake);
    }
    
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
         n = startTime.size();
         
         vector<vector<int>> arr(n, vector<int>(3, 0));
        
        for(int i = 0; i<n; i++){
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }
        
        sort(arr.begin(), arr.end());
        
        vector<int> memo(n,-1);
        
        return solve(0, arr, memo);
    }
};