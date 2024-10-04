class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        
        long res = 0;
        
        unordered_map<long, long> mp[n];
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                long long  diff = 1LL*nums[i]-1LL*nums[j];
                
                long count_at_j = 0;
                if(mp[j].find(diff)!=mp[j].end()){
                    count_at_j = mp[j][diff];
                }
                
                mp[i][diff] += count_at_j+1;
                res+=count_at_j;
            }
        }
        
        return res;
    }
};