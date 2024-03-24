class Solution {
public:
    char findTheDifference(string s, string t) {
         unordered_map<char, int> m1, m2;
        for(int i=0; i<s.size(); i++)m1[s[i]]++;
        for(int i=0; i<t.size(); i++)m2[t[i]]++;
        for(auto it: m1){
            if(m2.find(it.first)==m2.end())return it.first;
            else{
                if(it.second!=m2[it.first])return it.first;
                else{
                    m2.erase(it.first);
                }
            }
        }
        auto it= m2.begin();
        return (it)->first;
    }
};