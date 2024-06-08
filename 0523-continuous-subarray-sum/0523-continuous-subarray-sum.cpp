class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<2)return false;
        
        int mod = 0;
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        for(int i=0; i<n; i++){
            mod = (mod + nums[i])%k;
            
            if(mpp.find(mod)!=mpp.end()){
                if(i-mpp[mod]>1)
                    return true;
            }
            else mpp[mod] = i;
            
            
        }
        
        return false;
        
    }
};

//TC=O(n), SC=O(n)
// if mod is repeating , it means there is sum between these index where sum%k==0.