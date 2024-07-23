class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto &it : nums)st.insert(it);
        
        int longestSeq = 0;
        for(auto &it: nums){
            if(st.find(it-1)== st.end()){
                int cnt = 0;
                int cur = it;
                
                while(st.find(cur)!=st.end()){
                    cnt++;
                    cur++;
                }
                
                longestSeq = max(longestSeq, cnt);
            }
        }
        
        return longestSeq;
    }
};