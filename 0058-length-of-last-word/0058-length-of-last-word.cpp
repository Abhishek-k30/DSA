class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastSize=0;
        int n=s.size();
        bool flag=false;
        for(int i=n-1; i>=0; i--){
            if(s[i]!=' ')flag=true;
            if(flag){
            if(s[i]==' ')break;
            else lastSize++;
            }
        }
        
        return lastSize;
    }
};