class Solution {
private:
    void helper(vector<int>& nums, vector<int>& ds, vector<bool>& freq, vector<vector<int>> &ans){
        if(ds.size()== nums.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i = 0; i<nums.size(); i++){
            if(!freq[i]){
                freq[i] = true;
                ds.push_back(nums[i]);
                helper(nums, ds, freq, ans);
                ds.pop_back();
                freq[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> freq(nums.size(), false);
        helper(nums, ds, freq, ans);
        return ans;
    }
};