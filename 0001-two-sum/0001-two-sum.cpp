class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            m[nums[i]]=i;
        }
        for(int i=0; i<n; i++){
            int val=target-nums[i];
            if(m.find(val)!=m.end()){
                int ind=m[val];
                if(ind!=i){
                   ans={i,ind};
                   break;
                }
            }
            
        }
        
        return ans;
    }
};

// TC=O(nlogn), SC=O(n)