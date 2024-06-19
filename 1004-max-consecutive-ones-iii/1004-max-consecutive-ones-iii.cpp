class Solution {
private:
    bool good(vector<int>& nums, int k, int sz){
        int n = nums.size();
        int zero = 0;
        
        for(int i = 0; i<sz; i++){
            if(nums[i] == 0)
                zero++;
        }
        
        if(zero<=k)
            return true;
        
        int idx = 0;
        
        for(int i = sz; i<n; i++){
            if(nums[i] == 0)
                zero++;
            if(nums[idx]==0)
                zero--;
            
            idx++;
            
            if(zero<=k)
                return true;
        }
        
        return false;
    }
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        
        int l = 0 , r = n;
        int ans = 0;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(good(nums, k, mid)){
                ans = max(ans, mid);
                l = mid + 1;
            }
            else r = mid -1;
        }
        
        return ans;
    }
};