class Solution {
public:
    string removeOccurrences(string s, string part) {
        vector<char> st;
        int sz = part.size();
        string match = part;
        reverse(match.begin(), match.end());
        
        string cur = "";
        
        for(int i = 0; i<s.size(); i++){
            st.push_back(s[i]);
            cur = st.back()+cur;
            if(cur.size()>sz)cur.pop_back();
            
            while(cur == match){
                for(int i = 0; i<sz; i++){
                    st.pop_back();
                    cur.pop_back();
                }
                
                int idx = st.size()-1;
                while(idx>=0 && cur.size()<sz){
                    cur += st[idx--];
                }
                
                
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans+=st.back();
            st.pop_back();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};