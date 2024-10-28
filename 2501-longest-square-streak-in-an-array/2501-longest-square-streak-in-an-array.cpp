class Solution {
private:
    int solve(int idx, int prev, int n, vector<int>&nums){
        if(idx>=n){
            return 0;
        }
        
        int notPick = solve(idx+1, prev, n , nums);
        int pick = 0;
        if(prev==-1 || (long)(nums[prev])*(long)(nums[prev]) == nums[idx]){
            pick = 1 + solve(idx+1, idx, n, nums);
        }
        
        return max(pick, notPick);
    }
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        // DP LIS approch
        // int len = solve(0, -1, n, nums);
        // return (len == 1 ? -1 : len);
        
        // Binary Search
        
        int maxLen = 0;
        
        for(int i = 0; i<n; i++){
            long cur = nums[i];
            
            int squareStreak = 1;
            
            cur*=cur;
            while(cur<= nums.back()){
                if(binary_search(nums.begin(), nums.end(), cur)){
                    squareStreak++;
                }
                else break;
                
                cur*=cur;
            }
            
            if(squareStreak>1){
                maxLen = max(maxLen, squareStreak);
            }
        }
        
        
        return (maxLen == 0 ? -1 : maxLen);
        
        //TC = O(nlogn), SC = O(1)
    }
};