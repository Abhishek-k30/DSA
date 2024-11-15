class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int prev = -101;
        int k = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == prev)k++;
            else{
                prev = nums[i];
                nums[i-k] = nums[i];
            }
        }
        
        return n - k;
    }
};