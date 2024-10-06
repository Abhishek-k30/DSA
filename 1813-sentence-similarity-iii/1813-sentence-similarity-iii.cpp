class Solution {
private:
    void solve(string &s, deque<string>&st){
        string temp = "";
        for(int i = 0; i<s.size(); i++){
            if(s[i]==' '){
                st.push_back(temp);
                temp="";
            }
            else temp+=s[i];
        }
        
        if(temp.size())st.push_back(temp);
    }
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        deque<string> s1, s2;
        solve(sentence1, s1);
        solve(sentence2, s2);
        
        while(!s1.empty() && !s2.empty() && s1.front() == s2.front()){
            s1.pop_front();
            s2.pop_front();
        }
        
        while(!s1.empty() && !s2.empty() && s1.back() == s2.back()){
            s1.pop_back();
            s2.pop_back();
        }
        
        if(s1.empty() || s2.empty()){
            return true;
        }
        
        return false;
    }
};