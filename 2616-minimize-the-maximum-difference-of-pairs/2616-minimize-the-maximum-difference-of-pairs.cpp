class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int l = 0, r = nums[n-1] - nums[0];
        
        int ans = r;
        while(l<=r){
            int mid = l + (r - l)/2;
            int k = 0;
            
            for(int i = 1; i<n && k<p ; i++){
                if(nums[i] - nums[i-1] <= mid){
                    i++;
                    k++;
                }
            }
            
            if(k>= p){
                ans = min(ans, mid);
                r = mid - 1;
            }
            else l = mid + 1;
        }
        
        return ans;
    }
};