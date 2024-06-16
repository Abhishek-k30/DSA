class Solution {
private:
    int f(int ind, int prev, int cnt , vector<int>&nums, vector<vector<vector<int>>> &dp){
        if(ind==nums.size())
            return 0;
        int ans = -1;
        
        if(dp[ind][prev+1][cnt]!=-1)
            return dp[ind][prev+1][cnt];
        
        if(prev==-1){
            ans = max(ans, f(ind+1, -1, cnt, nums, dp));
            ans = max(ans, 1+ f(ind+1, ind, cnt, nums, dp));
        }
        else{
            if(nums[ind]==nums[prev]){
                ans = max(ans, 1+f(ind+1, ind, cnt, nums,dp));
            }
            else{
                ans = max(ans, f(ind+1, prev, cnt ,nums, dp));
                
                if(cnt>0)
                    ans = max(ans, 1+f(ind+1, ind, cnt-1, nums, dp));
            }
        }
        
        return dp[ind][prev+1][cnt] = ans;
    }
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(26, -1)));
        
        return f(0, -1, k, nums, dp);
    }
};