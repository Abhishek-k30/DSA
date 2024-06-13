class Solution {
private:
    int f(int ind, int n, vector<int> &nums, vector<int> &dp ){
        if(ind>=n)
            return 0;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        return dp[ind] = max(nums[ind] + f(ind+2,n,nums, dp ), f(ind+1,n, nums, dp));
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        
        return f(0, n, nums, dp);
        
    }
};