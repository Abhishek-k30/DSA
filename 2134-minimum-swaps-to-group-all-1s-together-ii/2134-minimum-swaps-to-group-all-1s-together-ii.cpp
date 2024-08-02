class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = 0;
        for(int i = 0; i<n; i++){
            if(nums[i])
                totalOnes++;
        }
        vector<int> temp(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            temp.push_back(nums[i]);
        }
        
        int zero = 0, ones  = 0;
        int mnSwap = INT_MAX;
        for(int i = 0; i<totalOnes; i++){
            if(temp[i])
                ones++;
            else zero++;
        }
        
        mnSwap = min(mnSwap, zero);
        for(int i = totalOnes; i<2*n; i++){
             if(temp[i])
                ones++;
            else zero++;
            
            if(temp[i-totalOnes])
                ones--;
            else zero--;
            
            mnSwap = min(mnSwap, zero);
        }
        
        return mnSwap;
        
    }
};