class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        vector<int> cnt(26, 1e9);
        vector<int> aux(26, 0);
        for(auto &c :  words){
            for(auto &it: c)aux[it-'a']++;
            for(int i=0; i<26; i++){
                cnt[i] = min(cnt[i], aux[i]);
                aux[i] = 0;
            }
        }
        
        for(int i=0; i<26; i++){
            for(int j=0; j<cnt[i]; j++){
                string p = "";
                p+='a'+i;
                ans.push_back(p);
            }
        }
        
        return ans;
    }
};