#define ll long long
class Solution {
public:
    multiset<ll> st;
    vector<ll>pre;
    ll cost(int l, int r){
        ll mx=*prev(st.end());
        
        ll sm= pre[r];
        if(l!=0)sm-=pre[l-1];
        ll k= r-l+1;
        ll cs= mx+ k*sm;
        
        return cs;
        
    }
    bool good(int l, int r, ll k){
        return cost(l, r)<=k;
    }
    int maximumRobots(vector<int>& ct, vector<int>& rc, long long budget) {
        int n=ct.size();
        int l=0, ans=0;
        pre.resize(n);
        pre[0]=rc[0];
        for(int i=1; i<n; i++)pre[i]=pre[i-1]+rc[i];
        
        for(int r=0; r<n; r++){
            st.insert(ct[r]);
            while(l<=r && !good(l, r, budget)){
                st.erase(st.find(ct[l]));
                l++;
            }
            
           ans=max(ans, r-l+1);
        }
        
        return ans;
        
    }
};