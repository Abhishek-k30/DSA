class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxreach=0;
        for(int i=0; i<n; i++){
            if(maxreach>=i){
                maxreach=max(maxreach, i+nums[i]);
            }
            else return false;
        }
        
        return true;
        
    }
};