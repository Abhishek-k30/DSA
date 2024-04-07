class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m1, m2;
        for(int i=0; i<ransomNote.size(); i++)m1[ransomNote[i]]++;
        for(int i=0; i<magazine.size(); i++)m2[magazine[i]]++;
        
        
        for(auto it: m1){
            if(m2.find(it.first)!=m2.end() && m2[it.first]>=it.second)continue;
            else return false;
        }
        
        return true;
    }
};