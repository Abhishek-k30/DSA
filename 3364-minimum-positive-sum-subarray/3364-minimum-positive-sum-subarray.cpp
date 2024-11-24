class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int mini = 1e9;
        vector<int> pre(nums.begin(), nums.end());
        for(int i = 1; i<n; i++){
            pre[i]+=pre[i-1];
        }
        
        for(int sz = l ; sz<=r; sz++){
            for(int i = 0; i<=n-sz; i++){
                int sum = pre[i+sz-1];
                if(i>0)sum-=pre[i-1];
                
                if(sum>0)mini = min(mini, sum);
            }
        }
        
        return (mini == 1e9 ? -1 : mini);
    }
};