class Solution {
private:
    void helper(int ind, vector<int> &nums, set<vector<int>> &hash){
        if(ind == nums.size()){
            hash.insert(nums);
            return;
        }
        
        for(int i = ind; i<nums.size(); i++){
            swap(nums[i], nums[ind]);
            helper(ind+1, nums , hash);
            swap(nums[i], nums[ind]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> hash;
        helper(0, nums, hash);
        vector<vector<int>> ans(hash.begin(), hash.end());
        return ans;
    }
};