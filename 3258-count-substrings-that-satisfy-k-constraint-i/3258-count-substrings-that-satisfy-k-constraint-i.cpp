class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int l = 0, ans = 0;
        int zero = 0 , one = 0;
        for(int r = 0 ; r<n; r++){
            if(s[r]=='0')zero++;
            else one++;
            
            while(zero>k && one>k){
                if(s[l]=='0')zero--;
                else one--;
                l++;
            }
            
            ans+=(r-l+1);
        }
        
        return ans;
    }
};