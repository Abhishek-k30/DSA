class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size();
        unordered_map<char, vector<int>> m;
        for(int i= 0; i<n; i++){
            m[s[i]].push_back(i);
        }
        
        int cnt = 0;
        int lastptr=-1;
        for(int i =0; i<t.size(); i++){
            if(m.find(t[i])!=m.end()){
               int idx = upper_bound(m[t[i]].begin(), m[t[i]].end(), lastptr)-m[t[i]].begin();
                if(idx>=0 && idx< m[t[i]].size() && m[t[i]][idx]>lastptr){
                    lastptr = m[t[i]][idx];
                    
                }
                else {
                    cnt+= (t.size()-i);
                    break;
                }
            }
            else {
                cnt+= (t.size()-i);
                break;
            }
        }
        
        return cnt;
    }
};