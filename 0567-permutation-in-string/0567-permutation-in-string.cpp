class Solution {
private:
    bool check(int f[], int g[]){
        for(int i = 0; i<26; i++){
            if(f[i]!=g[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int freq1[26] = {0};
        int freq2[26] = {0};
        for(auto &it: s1){
            freq1[it-'a']++;
        }
        
        int size = s1.size();
        if(size>s2.size())return false;
        for(int i = 0; i<size; i++){
            freq2[s2[i]-'a']++;
        }
        
        if(check(freq1, freq2) )return true;
        
        int idx = 0;
        for(int i = size; i<s2.size(); i++){
            freq2[s2[idx]-'a']--;
            freq2[s2[i]-'a']++;
            
            idx++;
           if(check(freq1, freq2) )return true;
        }
        
        return false;
         
    }
};