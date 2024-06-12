#define ll long long
class Solution {
public:
    
    const int mod = 1e9 + 7;
    long long rev(ll n){
        string rep = to_string(n);
        reverse(rep.begin(), rep.end());
        
        return stoll(rep);
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<ll, ll> m;
        
        for(int i=0; i<n; i++){
            m[(ll)nums[i]-rev(nums[i])]++;
        }
        
        ll ans = 0;
        
        for(int i= 0; i< n ; i++){
            ll cur = nums[i] - rev(nums[i]);
            
            m[cur]--;
            if(m[cur]<=0)
                m.erase(cur);
            
            if(m.find(cur)!=m.end()){
                ans+= (m[cur]%mod);
                ans%=mod;
            }
        }
        
        return ans;
        
    }
};