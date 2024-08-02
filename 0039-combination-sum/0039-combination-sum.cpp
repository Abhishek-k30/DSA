class Solution {
private:
    void helper(int ind, int target , vector<int>& arr,vector<int> &temp, vector<vector<int>> &ans){
        if(ind == arr.size()){
            if(target == 0)
                ans.push_back(temp);
            
            return;
        }
        
        if(arr[ind] <= target){
            temp.push_back(arr[ind]);
            helper(ind, target- arr[ind], arr, temp, ans);
            temp.pop_back();
        }
        
        helper(ind+1, target, arr, temp, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0, target, candidates, temp, ans);
        return ans;
    }
};