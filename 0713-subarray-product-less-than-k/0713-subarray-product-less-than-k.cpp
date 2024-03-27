class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0, ans=0, mul=1;
        for(int r=0; r<n; r++){
            mul*=nums[r];
            while(mul>=k && l<=r){
                mul/=nums[l];
                l++;
            }
            
            if(mul<k)
            ans+=max((r-l+1), 0);
            
        }
        
        return ans;
    }
};