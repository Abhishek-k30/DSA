class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> dp(n, 1);
        int maxi = 1;
        
        for(int i = 0; i<n; i++){
            for(int prev = 0; prev<i; prev++){
                if(nums[i] % nums[prev] == 0){
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            
            maxi = max(maxi, dp[i]);
        }
        
        vector<int> ans;
        int prev = -1;
        
        for(int i = n-1; i>=0; i--){
            if(dp[i] == maxi && (prev==-1 || prev % nums[i] ==0)){
                ans.push_back(nums[i]);
                maxi--;
                prev = nums[i];
            }
        }
        
        return ans;
    }
};