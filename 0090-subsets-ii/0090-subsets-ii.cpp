class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        for(int i = 0; i< (1<<n) ; i++){
            vector<int> cur;
            for(int j=0; j<n ; j++){
                if( i & (1<<j))
                    cur.push_back(nums[j]);
            }
            sort(cur.begin(), cur.end());
            st.insert(cur);
        }
        
        for(auto it : st)
            ans.push_back(it);
        
        return ans;
    }
};