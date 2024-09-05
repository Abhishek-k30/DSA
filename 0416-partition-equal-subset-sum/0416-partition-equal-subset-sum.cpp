class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum%2 == 1){
            return false;
        }
        
        int target = sum/2;
        
        vector<vector<bool>> dp(n+1, vector<bool>(target+1,false));
        for(int i = 0; i<n; i++){
            dp[i][0] = true;
        }
        for(int i = 0; i<n; i++){
            if(nums[i]<=target){
                dp[i][nums[i]] = true;
            }
        }
        for(int i = 1; i<n; i++){
            for(int j = 1; j<=target; j++){
                bool notTake = dp[i-1][j];
                bool take = false;
                if(nums[i]<=j){
                    take = dp[i-1][j-nums[i]];
                }
                
                dp[i][j] = take | notTake;
            }
        }
        
        return dp[n-1][target];
    }
};