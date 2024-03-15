class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total=1;
        int zero=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0)total*=nums[i];
            else zero++;
        }
        
        vector<int> ans;
         if(zero==nums.size()){
             vector<int> ans2(nums.size() , 0);
            return ans2;
        }
        
        if(zero==1){
             for(int i=0; i<nums.size(); i++){
                if(nums[i]==0)ans.push_back(total);
                else ans.push_back(0);
            }
        }
        else if(zero>1 && zero<nums.size()){
            vector<int> ans2(nums.size() , 0);
            return ans2;
        }
        
        else{
            for(int i=0; i<nums.size(); i++){
                ans.push_back(total/nums[i]);
            }
        }
        
        return ans;
        
    }
};