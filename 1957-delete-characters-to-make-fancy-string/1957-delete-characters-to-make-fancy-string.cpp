class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        int cnt = 0;
        string res = "";
        stack<char> st;
        
        for(int i = 0; i<n; i++){
            if(st.empty()){
                st.push(s[i]);
                res+=s[i];
                cnt = 1;
            }
            else{
                if(st.top() == s[i]){
                    if(cnt == 2)continue;
                    else{
                        st.push(s[i]);
                        res+=s[i];
                        cnt++;
                    }
                }
                else{
                    st.push(s[i]);
                    res+=s[i];
                    cnt = 1;
                }
            }
        }
        
        
        
       
        return res;
    }
};