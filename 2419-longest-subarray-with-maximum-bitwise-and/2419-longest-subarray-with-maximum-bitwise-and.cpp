class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int cnt = 0;
        int maxlen = 0;
        
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == maxi){
                cnt++;
                maxlen = max(maxlen, cnt);
            }
            else {
                cnt = 0;
            }
        }
        
        return maxlen;
    }
};