class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int mod = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        
        for(int i=0; i<n; i++){
            mod = (mod + nums[i]%k +k)%k;
           // cout<<mod<<endl;
            ans+=m[mod];
            
            m[mod]++;
        }
        
        return ans;
    }
};