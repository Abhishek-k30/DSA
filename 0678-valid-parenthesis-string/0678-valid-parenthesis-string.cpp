class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int cmin=0, cmax=0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                cmax++;
                cmin++;
            }
            if(s[i]==')'){
                cmax--;
                cmin=max(cmin-1, 0);
            }
            if(s[i]=='*'){
                cmax++;
                cmin=max(cmin-1, 0);
            }
            if(cmax<0)return false;
        }
        
        return cmin==0;
    }
};