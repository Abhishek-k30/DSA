class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int maxSize = 0;
        multiset<int> st;
        int l = 0;
        
        for(int r = 0; r<n; r++){
            st.insert(nums[r]);
            
            while(l<=r && abs(*st.begin() - *(prev(st.end()))) > limit){
                st.erase(st.find(nums[l]));
                l++;
            }
            
            maxSize = max(maxSize, r-l+1);
        }
        
        return maxSize;
    }
};