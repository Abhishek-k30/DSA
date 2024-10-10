class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> st;
        
        for(int i = 0; i<n; i++){
            if(st.empty() || nums[st.back()]>nums[i]){
                st.push_back(i);
            }
        }
        
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && nums[i] >= nums[st.back()]){
                ans = max(ans,i-st.back());
                st.pop_back();
            }
        }
        
        return ans;
    }
};