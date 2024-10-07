class Solution {
private:
    bool check(vector<char>&st){
        int n = st.size();
        string k = "";
        k+=st[n-2];
        k+=st[n-1];
        return k== "AB" || k=="CD";
    }
public:
    int minLength(string s) {
        int n = s.size();
        vector<char> st;
        for(int i = 0; i<n; i++){
            st.push_back(s[i]);
            while(st.size()>=2 && check(st)){
                st.pop_back();
                st.pop_back();
            }
        }
        
        return st.size();
    }
};