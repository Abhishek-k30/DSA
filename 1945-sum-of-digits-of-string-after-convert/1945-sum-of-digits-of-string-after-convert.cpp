class Solution {
private:
    string sum(string cur){
        int ans = 0;
        for(int i = 0; i<cur.size(); i++){
            ans+=(cur[i]-'0');
        }
        return to_string(ans);
    }
public:
    int getLucky(string s, int k) {
        string cur = "";
        for(int i = 0; i<s.size(); i++){
            int curVal = s[i]-'a' + 1;
            cur+=to_string(curVal);
        }
        while(k--){
            cur = sum(cur);
        }
        return stoi(cur);
    }
};