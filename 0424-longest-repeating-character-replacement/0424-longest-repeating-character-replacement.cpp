class Solution {
private:
    bool good(string s, int k, int sz){
        int n = s.size();
        vector<int> hash(26, 0);
        
        for(int i = 0; i<sz; i++){
            int cur = s[i] - 'A';
            hash[cur]++;
        }
        
        int mx = *max_element(hash.begin(), hash.end());
        
        int req = sz - mx;
        if(req<=k)
            return true;
        
        int idx = 0;
        for(int i = sz; i<n; i++){
            int cur1= s[i] - 'A';
            int cur2= s[idx] - 'A';
            hash[cur1]++;
            hash[cur2]--;
            idx++;
            
            mx = *max_element(hash.begin(), hash.end());
            req = sz - mx;
            if(req<=k)
            return true;
        }
        
        return false;
    }
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        
        int l = 0 , r = n;
        int ans = 0;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(good(s, k, mid)){
                ans = max(ans, mid);
                l = mid +1;
            }
            else r = mid -1;
        }
        
        return ans;
    }
};