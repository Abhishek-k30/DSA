class Solution {
public:
    unordered_map<int,int> m;
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0, ans=0, mx=0, mn=1e9;
        for(int r=0; r<n; r++){
            m[nums[r]]++;
            if(m[nums[r]]>k){
                while(m[nums[r]]>k){
                    m[nums[l]]--;
                    l++;
                }
            }
             
            
            
            ans=max(ans, r-l+1);
        }
        
        return ans;
    }
};