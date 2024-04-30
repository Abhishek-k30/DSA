class Solution {
public:
    int minOperations(vector<int>& nums, int val) {
        vector<int> cnt(32, 0);
        for(int i=0; i<nums.size(); i++){
            for(int k=0; k<32; k++)
            cnt[k]+=(nums[i]&(1<<k))>>k;
        }
        
        vector<int> match(32, 0);
        for(int k=0; k<32; k++){
            cnt[k]+=(val&(1<<k))>>k;
        }
        
        int ans=0;
        for(int i=0; i<32; i++){
            if(match[i]==0 && cnt[i]%2==1)ans++;
            else if(match[i]==1 && cnt[i]%2==0)ans++;
        }
        
        return ans;
    }
};