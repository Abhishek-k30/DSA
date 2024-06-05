class Solution {
public:
    int partitionString(string s) {
        int  n = s.size();
        unordered_set<char> st;
        int cnt = 0 , sz= 0 ;
        for(int i =0;  i<n; i++){
             if(st.find(s[i])!=st.end()){
                 cnt++;
                 st.clear();
                 st.insert(s[i]);
             }
            else st.insert(s[i]);
        }
         
        return cnt+ !st.empty();
    }
};