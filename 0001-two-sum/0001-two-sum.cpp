class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int , int> m;
        for(int i=0 ; i<n ; i++){
            int tofind=target-nums[i];
            
            if(m.find(tofind)!=m.end()){
                ans.push_back(m[tofind]);
                ans.push_back(i);
                break;
                
            }
            
            m[nums[i]]=i;
        }
        
        return ans;
    }
};