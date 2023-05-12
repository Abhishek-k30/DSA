class Solution {
public:
    int f(int ind, vector<int> nums, vector<int> &dp){
        int n=nums.size();
        
        // Base Case
         
        if(ind<0 || ind>=n)return 0;
        if(ind==n-1)return nums[ind];
        
        
        // Memoiation
        if(dp[ind]!=-1)return dp[ind];
        
        // Not Pick
        int notPick=f(ind+1,nums, dp);
        
        // Pick
        int Pick=nums[ind]+f(ind+2, nums, dp);
        
        // Return Maximum
        return dp[ind]=max(Pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int> t1(nums.begin()+1,nums.end()), t2(nums.begin(), nums.end()-1);
        
        vector<int> dp(n+1, -1), dp1(n+1,-1);
         
        
        return max(f(0,t1, dp), f(0,t2, dp1));
    }
};

//TC=O(N), SC=O(N)*4+O(N)
