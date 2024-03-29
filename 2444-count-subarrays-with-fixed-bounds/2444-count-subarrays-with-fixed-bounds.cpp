#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll n=nums.size();
        ll jmn=-1, jmx=-1, jbad=-1;
        ll ans=0;
        for(ll r=0; r<n; r++){
            if(nums[r]<minK || nums[r]>maxK)jbad=r;
            if(nums[r]==minK)jmn=r;
            if(nums[r]==maxK)jmx=r;
            
            ans+=max((ll)0, min(jmn, jmx)-jbad);
            
        }
        
        return ans;
    }
};