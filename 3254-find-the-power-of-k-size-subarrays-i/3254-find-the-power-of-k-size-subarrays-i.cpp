class Solution {
int powerValue(vector<int>&nums , int start, int end){
    int fs = nums[start];
    for(int i = start+1;i<=end; i++){
        if(nums[i]==fs+1){
            fs = nums[i];
        }
        else return -1;
    }
    return nums[end];
}
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> ans(n-k+1);
        
        for(int i = 0; i<n-k+1; i++){
            ans[i] = powerValue(nums, i, i+k-1);
        }
        
        return ans;
    }
};