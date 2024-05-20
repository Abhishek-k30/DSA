class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=1; i<(1<<n); i++){
            int total=0;
            for(int j=0; j<n; j++){
                if(i&(1<<j))total^=nums[j]; 
            }
            
            ans+=total;
        }
        
        return ans;
    }
};