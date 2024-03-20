class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int> dp(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[i]>nums[st.top()]){
                dp[i]=max(++dp[i], dp[st.top()]);
                st.pop();
                ans=max(ans, dp[i]);
            }
                  
            st.push(i);
        }
        
        return ans;
    }
};