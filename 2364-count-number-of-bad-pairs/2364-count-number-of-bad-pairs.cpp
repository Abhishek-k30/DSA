#define ll long long
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, ll> mpp;
        
        for(int i=0; i<n; i++){
            mpp[i-nums[i]]++;
        }
        
        ll ans = 0;
        ll cnt = n;
        
        for(int i = 0; i<n; i++){
            ll sum = cnt - mpp[i-nums[i]];
            ans += sum;
            
            cnt--;
            mpp[i-nums[i]]--;
        }
        
        return ans;
    }
};