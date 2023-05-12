class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        
        int best=INT_MIN;
        int maxProd=1;
        int minProd=1;
        
        for(int i=0; i<n; i++){
            if(nums[i]<0){
                swap(maxProd, minProd);
            }
            
            maxProd=max(maxProd*nums[i], nums[i]);
            minProd=min(minProd*nums[i], nums[i]);
            
            best=max(best, maxProd);
        }
        
        return best;
    }
};