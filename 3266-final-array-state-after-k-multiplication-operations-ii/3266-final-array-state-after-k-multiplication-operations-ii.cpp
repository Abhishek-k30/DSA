#define ll long long
class Solution {
public:
    int mod = 1e9+7;
    ll modpow(ll base, ll exp){
        ll result = 1;
        while(exp){
            if(exp&1){
                result*=base;
                result%=mod;
            }
            base*=base;
            base%=mod;
            exp>>=1;
        }
        return result;
    } 
    vector<int> getFinalState(vector<int>& nums, int k, int multi) {
        int n = nums.size();
        priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
        if(multi == 1){
            return nums;
        }
        ll mx = -1;
        for(int i = 0; i<n; i++){
            pq.push({nums[i], i});
            mx = max(mx, 1LL*nums[i]);
        }
        while(k && 1LL*multi*pq.top().first<=mx){
            k--;
            ll val = pq.top().first;
            ll ind = pq.top().second;
            pq.pop();
            
            val = (1LL*multi*val)%mod;
            pq.push({val, ind});
        }
        const ll pow = modpow(multi, k/n);
        while(!pq.empty()){
            ll val = pq.top().first;
            ll ind = pq.top().second;
            pq.pop();
            
            if(k%n){
                nums[ind] = (((1LL*multi*pow)%mod)*val)%mod;
                k--;
            }
            else{
                nums[ind] = (1LL*pow*val)%mod;
            }
            
        }
        
        return nums;
    }
};