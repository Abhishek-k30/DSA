class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        map<int, int> m({{0,1}});
        int pre=0;
        int ans=0;
        for(int i:nums){
            pre+=i;
            ans+=m[pre-goal];
            m[pre]++;
        }
        
        return ans;
        
         
    }
};