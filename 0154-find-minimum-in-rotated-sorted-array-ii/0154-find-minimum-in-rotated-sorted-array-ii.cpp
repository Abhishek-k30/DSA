class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0, high=n-1;
        int ans= INT_MAX;
        
        
        while(low<=high){
             ans=min({ans, nums[low], nums[high]});
             low++;
             high--;
             
        }
       return ans;
    }
};