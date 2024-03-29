class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n=nums.size();
        long long l=0, ans=0;
        unordered_map<long long, long long> m;
        long long mx=*max_element(nums.begin(), nums.end());
        for(long long r=0; r<n ; r++){
            m[nums[r]]++;
            while(m[mx]>=k){
                m[nums[l]]--;
                l++;
            }
            
            if(m[mx]<k)
                ans+=(r-l+1);
            
        }
        
        long long total= (n*(n+1))/2;
        return total-ans;
    }
};