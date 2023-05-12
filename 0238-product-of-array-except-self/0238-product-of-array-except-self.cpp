class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int prod=1;
        int zero=0;
        int c=0;
        int z=0;
        int n=nums.size();
//         vector<int> zr(n);
        
//         for(int i=0; i<n; i++){
//             if(nums[i]==0)z++;
            
//             zr[i]=z;
//         }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                zero++;
            }
            else{
                prod*=nums[i];
                c=1;
            }
        }
        if(zero==nums.size())prod=0;
        
        
        // If number of zeros will be greater then 0 then index having zero will give total Product           // otherwise it will give zero product; 
        if(zero>1){
            for(int i=0; i<nums.size(); i++){
                if(nums[i]==0){
                    if(zero>=1){
                        ans.push_back(0);
                        zero--;  
                    }
                    else ans.push_back(prod);
                }
                else{
                    ans.push_back(0);
                }
            }
        }
        else if(zero==1){
            for(int i=0; i<nums.size(); i++){
                if(nums[i]==0){
                     
                     
                     ans.push_back(prod);
                }
                else{
                    ans.push_back(0);
                }
            }
        }
        else{
            for(int i=0; i< nums.size(); i++){
                ans.push_back(prod/nums[i]);
            }
        }
        return ans;
    }
};

// TC=O(N), SC=O(N)