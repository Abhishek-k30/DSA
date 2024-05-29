#define ll long long
class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        ll n = nums.size();
        unordered_map<ll, ll> m;
        ll cnt =0;
        for(int i=0; i<n; i++){
            ll gcd = __gcd(nums[i], k);
            for(auto &it: m){
                if(gcd*it.first%k==0){
                    cnt+=it.second;
                }
            }
            m[gcd]++;
        }
        
        return cnt;
    }
};