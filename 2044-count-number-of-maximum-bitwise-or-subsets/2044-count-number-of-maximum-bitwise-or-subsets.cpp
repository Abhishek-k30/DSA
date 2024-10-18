class Solution {
public:
    int cnt = 0;
    void solve(int idx, int n, int cur_or, int max_or, vector<int>&nums){
        if(idx>=n){
            if(cur_or == max_or){
                cnt++;
            }
            return;
        }
        
        solve(idx+1, n, cur_or, max_or, nums);
        solve(idx+1, n, cur_or|nums[idx], max_or, nums);
        cur_or &= ~nums[idx];
        
        return;
        
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int max_or = 0;
        for(auto &it: nums)max_or|=it;
        
         
        solve(0, n,  0, max_or, nums);
        
        
        return cnt;
    }
};