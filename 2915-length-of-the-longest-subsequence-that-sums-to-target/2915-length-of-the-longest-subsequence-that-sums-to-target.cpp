class Solution {
private:
    int f(int ind, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(target == 0)
            return 0;
        
        if(target < 0 || ind >= nums.size())
            return -1001;
        if(dp[ind][target]!=-1001)
            return dp[ind][target];
        
        int notTake = f(ind+1, target, nums, dp);
        
        int take = 1 + f(ind+1, target - nums[ind], nums, dp);
        
        return dp[ind][target] = max(take, notTake);
    }
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1001));
        
        int ans = f(0, target, nums, dp);
        if(ans >0)
            return ans;
        else return -1;
    }
};