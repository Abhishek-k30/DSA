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
        if(n==1)
            return nums[0];
        vector<int> dp(nums);
        
        //return f(0, n, nums, dp);
        
        dp[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i<n; i++){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        
        return dp[n-1];
    }
};