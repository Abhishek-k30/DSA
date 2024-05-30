class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans(n);
        int start = pref[0];
        ans[0] = start;
        for(int i=1; i<n; i++){
            int cur = pref[i]^start;
            ans[i] = cur;
            start^=ans[i];
            
        }
        
        return ans;
    }
};