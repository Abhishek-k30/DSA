#define ll long long
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n=nums.size();
        vector<ll> ans(n, 0);
        unordered_map<ll, ll> m;
        set<pair<ll, ll>> st;
        for(int i=0; i<n; i++){
            ll f= m[nums[i]];
            auto it= st.find({f,nums[i]});
            if(it!=st.end())st.erase(it);
            m[nums[i]]+=freq[i];
            st.insert({m[nums[i]], nums[i]});
            
            ans[i]=st.rbegin()->first;
        }
        return ans;
    }
};