#define ll long long
class Solution {
ll compute(vector<ll> &pre, ll ind , ll n, vector<ll> &ones, ll k){
    ll n1 = (k-1)/2;
    ll front = pre[ind+1+ n1] - pre[ind+1] - (n1)*ones[ind] - ((n1)*(n1+1))/2;
    
    ll back = (k/2)*ones[ind] - pre[ind]+pre[ind-(k/2)] - (k/2 * (k/2+1))/2;
    
    return front+back;
}
public:
    int minMoves(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> ones;
        
        for(int i = 0; i<n; i++){
            if(nums[i]==1)
                ones.push_back(i);
        }
        
        
         
        vector<ll> pre={0};  
        int n1 = ones.size();
	   for(int i=0;i<n1;i++)
		pre.push_back(pre.back()+ones[i]);

        ll ans = 1e14;
        
        for(int i=k/2; i< n1-(k-1)/2; i++){
            ll cur = compute(pre, i, ones.size(), ones, k);
            
            ans = min(ans, cur);
        }
        
        return ans;
        
    }
};