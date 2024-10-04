class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto &it: nums){
            m[it]++;
        }
        
        int cnt = 0;
        for(int i = 0; i<nums.size(); i++){
            int cur = nums[i];
            int tar = k-nums[i];
            
            if(cur == tar){
                if(m[cur]>1){
                    cnt++;
                    m[cur]-=2;
                    if(m[cur]<=0)m.erase(cur);
                }
            }
            else{
                if(m[cur]>0 && m[tar]>0){
                    cnt++;
                    m[cur]--;
                    m[tar]--;
                    if(m[cur]<=0)m.erase(cur);
                    if(m[tar]<=0)m.erase(tar);
                }
            }
        }
        return cnt;
    }
};