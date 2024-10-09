class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        int cnt = 0;
        for(auto &it: s){
            if(it == '('){
                open++;
            }
            else {
                if(open>0)open--;
                else cnt++;
            }
        }
        
        int ans = open + cnt;
        return ans;
    }
};