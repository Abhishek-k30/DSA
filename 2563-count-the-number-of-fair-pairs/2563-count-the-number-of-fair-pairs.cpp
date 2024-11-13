class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        long long fairPairs = 0;
        
        for(int i = 0; i<n; i++){
            int lowerBound = lower - nums[i];
            int upperBound = upper - nums[i];
            
            // Total no of idx between lowerBound and upper Bound
            int firstPos = lower_bound(nums.begin() + (i+1), nums.end(), lowerBound) - nums.begin();
            int lastPos = upper_bound(nums.begin() + (i+1), nums.end(), upperBound)
                -nums.begin();
            
            fairPairs+= (lastPos-firstPos);
        }
        
        return fairPairs;
    }
};