class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> pre(n,0);
        pre[0]=nums[0];
        for(int i=1; i<n; i++)pre[i]=nums[i]+pre[i-1];
        long long ans=1e10;
        for(long long i=0; i<n; i++){
            long long right= ( pre.back()-pre[i])-(n-i-1)*(1LL*nums[i]);
            long long left= 0;
            if(i>0){
                left= i*(1LL*nums[i])-pre[i-1];
            }
            
            ans=min(ans, left+right);
        }
        
        
        return ans;
        
    }
};