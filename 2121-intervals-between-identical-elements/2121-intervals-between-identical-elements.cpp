#define ll long long
class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        
        vector<ll> ans(n, 0);
        unordered_map<int, ll> m, m1;
        
        for(ll i=0; i<n; i++){
            ll sum = 0;
            if(m.find(arr[i])!=m.end()){
                  sum = abs(m[arr[i]] - (m1[arr[i]])*(i));
                ans[i] = sum;
            }
            
            m[arr[i]]+=i;
            m1[arr[i]]++;
        }
        
        m.clear();
        m1.clear();
        
        for(ll i=n-1; i>=0; i--){
            ll sum = 0;
            if(m.find(arr[i])!=m.end()){
                  sum = abs(m[arr[i]] - (m1[arr[i]])*(i));
                ans[i]+= sum;
            }
            
            m[arr[i]]+=i;
            m1[arr[i]]++;
        }
        
        return ans;
    }
};