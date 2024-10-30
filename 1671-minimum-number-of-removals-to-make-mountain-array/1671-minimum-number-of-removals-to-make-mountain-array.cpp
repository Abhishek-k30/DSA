class Solution {
private:
    int dp[1005][1005][3];
     int solve(int idx, int prev,int sign, vector<int>&nums){
          
         if(idx>=nums.size()){
             return 0;
         }
         
         if(dp[idx][prev+1][sign+1]!=-1)return dp[idx][prev+1][sign+1];
         
         int notTake = solve(idx+1, prev, sign, nums);
         int take = 0;
         if(prev == -1)take = 1+solve(idx+1,idx, 0, nums);
         else if(sign == 0 && idx<nums.size()-1 && nums[idx]>nums[prev]){
             
             take = 1 +
                     max( solve(idx+1, idx, 0, nums), solve(idx+1,idx, 1, nums ));
         }
         else if(sign == 1 && nums[idx]<nums[prev]){
             take = 1 + solve(idx+1, idx, 1, nums);
         }
         
         
         return dp[idx][prev+1][sign+1] = max(take, notTake);
     }
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        // memset(dp, -1, sizeof(dp));
        // int maxMountainLen = solve(0, -1, -1, nums);
        // return n - maxMountainLen;
        vector<int>dp1(n,1);
        vector<int>dp2(n,1);
        

        for(int i=0;i<n;i++)
        {
            
            for(int prev=0;prev<i;prev++)
            {
                if( nums[prev]< nums[i] && 1+dp1[prev]>dp1[i]){
                    dp1[i]=1+dp1[prev]; 
                }
            }
           
                
        }

        for(int i=n-1;i>=0;i--)
        {
            
            for(int prev=n-1;prev>i;prev--)
            {
                if( nums[prev]< nums[i] && 1+dp2[prev]>dp2[i]){
                    dp2[i]=1+dp2[prev]; 
                }
            }
           
                
        }
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            if(dp1[i]==1||dp2[i]==1) continue;
            maxi=max(maxi,dp1[i]+dp2[i]-1);
        }
       return n-maxi;
    }
};