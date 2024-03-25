class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        int add=1e5;
        for(int i=0; i<n; i++){
            int ind= nums[i]-1;
            if(ind>=2*add)ind-=2*add;
            else if(ind>=add)ind-=add;
            nums[ind]+= add;
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(nums[i]>2*add)ans.push_back(i+1);
        }
        
         return ans;
        
        
    }
};