class Solution {
private:
    int f(int ind, int reqSum, vector<int> &nums, vector<vector<int>> &dp){
        if(ind == 0){
            if(reqSum==0 && nums[0]==0)return 2;
            if(reqSum==0 || nums[0]==reqSum)return 1;
            return 0;
        }
        
        if(dp[ind][reqSum]!=-1)
            return dp[ind][reqSum];
        
        int notTake = f(ind-1, reqSum, nums, dp);
        int take = 0;
        if(nums[ind]<=reqSum)
            take = f(ind-1, reqSum - nums[ind], nums, dp);
        
        return dp[ind][reqSum] = take + notTake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        int reqSum = (totalSum - target)/2;
        if(totalSum<target || (totalSum-target)%2==1)
            return 0;
        vector<vector<int>> dp(n+1, vector<int>(reqSum+1, -1));
        
        return f(n-1, reqSum, nums, dp);
        
    }
};