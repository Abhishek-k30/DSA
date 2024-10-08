class Solution {
public:
    unordered_map<string, int> mpp;
    bool solve(string s1, string s2){
        if(s1 == s2){
            return true;
        }
        
        if(s1.size()!=s2.size()){
            return false;
        }
        
        string key = s1 + "-" + s2;
        if(mpp.find(key)!=mpp.end()){
            return mpp[key];
        }
        bool result = false;
        int n = s1.size();
        for(int i = 1; i<s1.size(); i++){
        bool swapped = solve(s1.substr(0, i) , s2.substr(n-i, i))
                        &&
                        solve(s1.substr(i, n-i), s2.substr(0, n-i));
            
        if( swapped){
                result = true;
                break;
            }
           
        bool notSwapped = solve(s1.substr(0, i), s2.substr(0, i))
                        &&
                         solve(s1.substr(i, n-i), s2.substr(i,n-i));
            
            
            if( notSwapped){
                result = true;
                break;
            }
        }
        
        return mpp[key] = result;
    }
    bool isScramble(string s1, string s2) {
         
        
        return solve(s1,s2);
    }
};