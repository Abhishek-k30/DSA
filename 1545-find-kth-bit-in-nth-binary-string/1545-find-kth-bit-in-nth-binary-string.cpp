class Solution {
private:
    string invert(string s){
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='0')s[i] = '1';
            else s[i] = '0';
        }
        
        return s;
    }
    string reverse(string s){
        for(int i = 0; i<s.size()/2; i++){
            swap(s[i], s[s.size()-1-i]);
        }
        
        return s;
    }
public:
    string solve(int n){
        if(n==1){
            return "0";
        }
        
        return solve(n-1) + "1" + reverse(invert(solve(n-1)));
    }
    char findKthBit(int n, int k) {
        string finalString  = solve(n);
        return finalString[k-1];
    }
};