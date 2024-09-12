class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st(allowed.begin(),allowed.end());
        int cnt = 0;
        
        for(auto &it: words){
            bool flag = true;
            for(char c: it){
                if(st.find(c)==st.end()){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cnt++;
            }
        }
        
        return cnt;
    }
};