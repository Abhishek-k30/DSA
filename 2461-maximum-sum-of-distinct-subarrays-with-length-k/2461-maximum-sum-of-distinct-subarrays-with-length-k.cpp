class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxi = 0 ;
        long long curSum = 0;
        
        unordered_map<int, int> hash;
        
        for(int i = 0; i<k; i++){
            curSum+=nums[i];
            hash[nums[i]]++;
        }
        
        if(hash.size() == k)maxi = max(maxi, curSum);
        
        for(int i = k; i<n; i++){
            hash[nums[i-k]]--;
            if(hash[nums[i-k]]== 0)hash.erase(nums[i-k]);
            hash[nums[i]]++;
            curSum+= (nums[i]-nums[i-k]);
            
            if(hash.size() == k)maxi = max(maxi, curSum);
        }
        
        return maxi;
    }
};