class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        multiset<int> st;
        for(int i=0; i<k; i++)st.insert(nums[i]);
        ans.push_back(*prev(st.end()));
        for(int i=1; k-1+i<n; i++){
            int remove= nums[i-1];
            st.erase(st.find(remove));
            st.insert(nums[k-1+i]);
            ans.push_back(*prev(st.end()));
        }
        
        return ans;
    }
};