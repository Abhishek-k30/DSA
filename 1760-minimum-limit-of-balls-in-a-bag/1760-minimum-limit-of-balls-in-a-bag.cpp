class Solution {
public:
    bool check(vector<int>& nums, int k, int div){
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            cnt+= (nums[i]-1)/div;
            
        }
        
        if(cnt<=k)return true;
        return false;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int low=1, high=1e9;
        int ans=-1;
        while(low<=high){
            int mid=low+ (high-low)/2;
            if(check(nums, maxOperations, mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
            
        }
        
        return ans;
    }
    
};