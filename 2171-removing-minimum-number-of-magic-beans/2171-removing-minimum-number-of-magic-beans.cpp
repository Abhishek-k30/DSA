#define ll long long
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(beans.begin(), beans.end());
        ll ops = 1e14;
        vector<ll> prefix(n, 0);
        prefix[0] = beans[0];
        
        for(int i = 1; i<n; i++){
            prefix[i] = prefix[i-1] + beans[i];
        }
        
        for(int i = 0; i<n; i++){
            ll prevSum = 0;
            if(i>0)prevSum = prefix[i-1];
            
            ll frontSum = prefix[n-1] - prevSum -   1LL*(n-i) * beans[i];
            
            ops = min(ops, prevSum + frontSum);
        }
        
        return ops;
        
    }
};