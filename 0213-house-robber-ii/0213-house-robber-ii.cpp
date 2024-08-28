class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int> temp1(nums.begin()+1, nums.end());
        vector<int> temp2(nums.begin(), nums.end()-1);
        
        vector<int> dp1(n, 0), dp2(n, 0);
        for(int i = 0; i<n-1; i++){
            int lastPrev = 0 , prev = 0;
            if(i-2>=0)lastPrev = dp1[i-2];
            if(i-1>=0)prev = dp1[i-1];
            
            dp1[i] = max(temp1[i]+lastPrev, prev);
        }
        for(int i = 0; i<n-1; i++){
            int lastPrev = 0 , prev = 0;
            if(i-2>=0)lastPrev = dp2[i-2];
            if(i-1>=0)prev = dp2[i-1];
            
            dp2[i] = max(temp2[i]+lastPrev, prev);
        }
        
        return max(dp1[n-2], dp2[n-2]);
            
    }
};