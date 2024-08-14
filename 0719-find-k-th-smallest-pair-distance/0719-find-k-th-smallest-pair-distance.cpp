class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 0 , high = nums[n-1]-nums[0];
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            int cnt = 0;
            int l = 0, r = 1;
            for(r = 1; r<n; r++){
                while(abs(nums[r]-nums[l])>mid){
                    l++;
                }
                
                cnt+= (r-l);
            }
            
            if(cnt>=k){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        
        return ans;
    }
};