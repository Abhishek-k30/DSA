class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n=nums.size();
        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            m[nums[i]]=i;
        }
        
        for(int i=0; i<operations.size(); i++){
            int idx= m[operations[i][0]];
            int change=operations[i][1];
            nums[idx]=change;
            m.erase(operations[i][0]);
            m[change]=idx;
            
        }
        
        return nums;
        
    }
};