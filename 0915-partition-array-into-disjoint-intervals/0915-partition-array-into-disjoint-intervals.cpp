class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int  n = nums.size();
        int maxi =  nums[0];
        vector<int> mini(n);
        int mn = INT_MAX;
        for(int i = n-1; i>=0; i--){
            mn = min(mn, nums[i]);
            mini[i] = mn;
        }
        
        int cnt = 1;
       
        for(int i=1; i<n; i++){
            
            if(nums[i] >=maxi && maxi<= mini[i]){
                break;
            }
            
            maxi = max(maxi, nums[i]);
            
            cnt++;
            
        }
        
        return cnt;
    }
};