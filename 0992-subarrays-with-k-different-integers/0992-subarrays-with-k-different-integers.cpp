class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k)-atMostK(nums, k-1);
    }
    int atMostK(vector<int> & nums, int k){
        int n=nums.size();
        int l=0, ans=0;
        unordered_map<int, int> m;
        for(int r=0; r<n; r++){
            m[nums[r]]++;
            while(m.size()>k){
                m[nums[l]]--;
                if(m[nums[l]]<=0)
                    m.erase(nums[l]);
                
                l++;
            }
            
            ans+= r-l+1;
        }
        
        return ans;
    }
};