class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        stack<char> st;
        int ans=0;
        for(int i=0; i<n; i++){
            if(s[i]!='(' && s[i]!=')')continue;
            else if(s[i]=='('){
                st.push('(');
                ans=max(ans, (int)st.size());
            }
            else{
                if(!st.empty())
                st.pop();
            }
        }
        
        return ans;
    }
};