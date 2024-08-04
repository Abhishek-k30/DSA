#define ll long long
class Solution {
public:
    const int mod = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<ll> subarraysum;
        for(int i = 0; i<n; i++){
            ll sum = 0;
            for(int j = i; j<n; j++){
                sum+=1LL*nums[j];
                subarraysum.push_back(sum);
            }
        }
        
        sort(subarraysum.begin(), subarraysum.end());
        ll ans = 0;
        for(int i = left-1; i<right; i++){
            ans+= (subarraysum[i])%mod;
        }
        return ans%mod;
    }
};