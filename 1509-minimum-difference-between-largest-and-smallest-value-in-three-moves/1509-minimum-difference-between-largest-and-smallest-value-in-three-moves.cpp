class Solution {
public:
    int minDifference(vector<int>& nums) {
        
        // 2 3 4 5 6 7 8 9
        
        // 0 1 5 10 14
        
        int n = nums.size();
        
        int ans = INT_MAX;
        
        sort(nums.begin(), nums.end());
        
        
        if(n<=4){
            return 0;
        }
        int l = 0, r = n-4;
        
        
        for(int i=0; i<4; i++){
            ans = min(ans, abs(nums[l]-nums[r]));
            l++;
            r++;
        }
        
        return ans;
    }
};