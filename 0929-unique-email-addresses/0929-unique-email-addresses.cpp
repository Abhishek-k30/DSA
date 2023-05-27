class Solution {
public:
    string check(string s){
        string local="";
        string domain="";
        int ind=0;
        bool flag=true;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='@'){
                ind=i+1;
                break;
            }
            if(s[i]=='+')flag=false;
            if(s[i]=='.')continue;
            
            else {
                if(flag) {
                   local+=s[i];
                    
                }
                    
            }
        }
        
        for(int i=ind; i<s.size(); i++){
            domain+=s[i];
        }
        
        return local+"@"+domain;
        
        
    }
    int numUniqueEmails(vector<string>& emails) {
       unordered_set<string> st;
       for(int i=0; i<emails.size(); i++){
           string val=check(emails[i]);
           st.insert(val);
       }
        
        return st.size();
    }
};