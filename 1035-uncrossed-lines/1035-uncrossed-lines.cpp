class Solution {
public:
    int f(int i, int j, vector<int> nums1, vector<int> nums2,vector<vector<int>> &dp ){
        int n=nums1.size(), m=nums2.size();
        // Base Case
        if(i==n || j==m)return 0;
        int count=0;
        
        // Memoization
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        
        
        //If the element is equal in both the vector at index i and j
        if(nums1[i]==nums2[j]){
            // increase the count by one
            
            count=1+ f(i+1, j+1,nums1, nums2, dp);
        }
        else{
            // we will take the maximum between two subsegments
            
            count=max(f(i+1, j, nums1, nums2, dp), f(i, j+1, nums1, nums2, dp));
        }
        
        return dp[i][j]=count;
        
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return f(0, 0, nums1, nums2, dp);
        
        
        
    }
};