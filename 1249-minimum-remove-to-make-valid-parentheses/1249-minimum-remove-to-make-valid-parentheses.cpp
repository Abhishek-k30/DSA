class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        string ans="";
        stack<char> st;
        int open=0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                ans+=s[i];
                st.push(s[i]);
                //open++;
            }
            else if(s[i]==')'){
                if(!st.empty()){
                    ans+=s[i];
                    st.pop();
                }
            }
            else ans+=s[i];
        }
        
        string ans2="";
        open=st.size();
        //cout<<open<<endl;
        for(int i=ans.size()-1; i>=0; i--){
            if(ans[i]=='('){
                if(open>0)open--;
                else ans2+=('(');
            }
            else if(ans[i]==')')ans2+=(')');
            else ans2+=ans[i];
        }
        
        
        reverse(ans2.begin(), ans2.end());
         
        return ans2;
       
    }
};