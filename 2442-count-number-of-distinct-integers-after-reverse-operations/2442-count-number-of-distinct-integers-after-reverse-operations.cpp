class Solution {
public:
    int reverse1(int num){
         string cur = to_string(num);
         reverse(cur.begin(), cur.end());
        return stoi(cur);
    }
    int countDistinctIntegers(vector<int>& nums) {
        int  n = nums.size();
        unordered_set<int> st;
        for(auto & it :  nums)
            st.insert(it);
        
        for(auto &it : nums){
            st.insert(reverse1(it));
        }
        
        return st.size();
    }
};