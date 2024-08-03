class Solution {
private:
    void helper(int ind, vector<int> & nums, vector<vector<int>> &ans){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i = ind; i<nums.size(); i++){
            swap(nums[i], nums[ind]);
            helper(ind+1, nums, ans);
            swap(nums[i], nums[ind]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        // vector<int> ds;
        // vector<bool> freq(nums.size(), false);
        helper(0, nums, ans);
        return ans;
    }
};