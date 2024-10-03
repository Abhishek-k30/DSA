class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = accumulate(nums.begin(), nums.end(), (long long)0);
        int rem = sum%p;
        if(rem == 0)return 0;
        int l = 0;
        int len = nums.size();
        long long curSum = 0;
        map<long long, int> mpp;
        mpp[0] = -1;
        
        int cur = 0;
        for(int i = 0; i<nums.size(); i++){
             cur =(cur+nums[i])%p;
             int req = (cur-rem+p)%p;
            
            if(mpp.find(req)!=mpp.end()){
                len = min(len, i-mpp[req]);
            }
            
            mpp[cur] = i;
        }
        
        return (len == nums.size() ? -1 : len);
    }
};