class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> st1, st2;
        
        string cur = "";
        for(int i = 0; i<s1.size(); i++){
            if(s1[i] == ' '){
                st1[cur]++;
                cur = "";
            }
            else cur+=s1[i];
        }
        if(cur.size())st1[cur]++;
        cur = "";
        for(int i = 0; i<s2.size(); i++){
            if(s2[i] == ' '){
                st2[cur]++;
                cur = "";
            }
            else cur+=s2[i];
        }
        if(cur.size())st2[cur]++;
        
        
        vector<string> ans;
        cur = "";
        for(int i = 0; i<s1.size(); i++){
            if(s1[i] == ' '){
                if(st2.find(cur) == st2.end() && st1[cur] == 1){
                    ans.push_back(cur);
                }
                
                cur = "";
            }
            else cur+=s1[i];
        }
        
        if(cur.size() && st2.find(cur) == st2.end() && st1[cur] == 1){
            ans.push_back(cur);
        }
        
        cur = "";
        
          for(int i = 0; i<s2.size(); i++){
            if(s2[i] == ' '){
                if(st1.find(cur) == st1.end() && st2[cur] == 1){
                    ans.push_back(cur);
                }
                
                cur = "";
            }
            else cur+=s2[i];
        }
        
        if(cur.size() && st1.find(cur) == st1.end() && st2[cur]==1){
            ans.push_back(cur);
        }
        
        return ans;
    }
};