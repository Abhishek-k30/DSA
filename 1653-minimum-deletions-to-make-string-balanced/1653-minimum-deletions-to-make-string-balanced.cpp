class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int cnt = 0;
        stack<char> st;
        
        for(int i = n-1; i>=0; i--){
            if(!st.empty() && st.top() < s[i]){
                st.pop();
                cnt++;
            }
            else st.push(s[i]);
        }
        
        return cnt;
    }
};