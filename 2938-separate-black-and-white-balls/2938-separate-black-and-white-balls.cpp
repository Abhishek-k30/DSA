class Solution {
public:
    long long minimumSteps(string s) {
        long long n = s.size();
 
        long long oneCnt = 0;
        
        for(int i = 0; i<n; i++){
            if(s[i]=='1')oneCnt++;
        }
        
        long long steps = 0;
        
        for(int i = 0; i<n; i++){
            if(s[i]=='1'){
                 
                 steps += (n-(oneCnt-1))-(i+1);
                 oneCnt--;
                 
            }
        }
        
        return steps;
    }
};