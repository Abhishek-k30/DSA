class Solution {
public:
    const int mod = 1e9 + 7;
    int sumDistance(vector<int>& temp, string s, int d) {
        int n = temp.size();
        vector<long long> nums(n);
        for(int i = 0; i<n; i++){
            int cur = temp[i];
            long long dist = 1LL*cur + 1LL*(s[i] == 'R' ? d : -d);
            nums[i] = dist;
        }
        
        sort(nums.begin(), nums.end());
        vector<long long> pre(nums.begin(), nums.end());
        for(int i = 1; i<n; i++){
            pre[i] = (pre[i]  + pre[i-1]);
        }
        
        long long ans = 0;
        
        for(int i = 0; i<n; i++){
            ans= ans%mod + 
                ((pre[n-1] - pre[i]) - ((1LL*nums[i]) * (1LL*(n-i-1))))%mod;
        }
        
        return ans;
    }
};