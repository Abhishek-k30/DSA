class Solution {
private:
    int f(int ind, int prev, vector<int>& nums, vector<vector<int>> &dp){
        if(ind == nums.size())
            return 0;
        
        if(dp[ind][prev+1]!=-1)
            return dp[ind][prev+1];
        
        int notTake = f(ind+1, prev, nums, dp);
        int take = 0;
        
        if(prev==-1 || nums[ind] > nums[prev])
            take = 1 + f(ind+1, ind, nums, dp);
        
        return dp[ind][prev+1] = max(take, notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        
        return f(0, -1, nums, dp);
    }
};