class Solution {
public:
    bool rotateString(string s, string goal) {
        int n1 = s.size();
        int n2 = goal.size();
        if(n1!=n2)return false;
        
        for(int i = 0; i<n1; i++){
            string cur = "";
            for(int j = i+1; j<n1; j++){
                cur+=s[j];
            }
            for(int j = 0; j<=i; j++){
                cur+=s[j];
            }
            
            if(cur == goal)return true;
        }
        
        return false;
    }
};