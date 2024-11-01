class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        int cnt = 0;
        string res = "";
        char lastChar ;
        
        for(int i = 0; i<n; i++){
            if(cnt == 0){
                res+=s[i];
                lastChar = s[i];
                cnt = 1;
            }
            else if(lastChar == s[i]){
                if(cnt == 2)continue;
                else{
                    cnt++;
                    res+=s[i];
                }
            }
            else{
                cnt = 1;
                res+=s[i];
                lastChar = s[i];
            }
        }
        
        
        
       
        return res;
    }
};