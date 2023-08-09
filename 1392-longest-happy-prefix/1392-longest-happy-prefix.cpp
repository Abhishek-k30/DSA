using ul = unsigned long;
class Solution {
public:
    unordered_map<ul, int> hash; // hashcode -> str len
    const int B = 29;
    // const ul md = 1e9 + 7;
    const ul md = 124567987631;
    string longestPrefix(string s) {
        int n = s.size();
        ul pow = 1, ha = 0;
        // hashing
        for (int i = 0; i < n; i++) {
            ha += pow * s[i];
            ha %= md;
            pow = (pow * B) % md;
            
            hash[ha] = i + 1;
        }
        pow = 1, ha = 0;
        int len = 0;
        // hash in reverse order (omit i = 0, since that is when str == str)
        for (int i = n - 1; i > 0; i--) {
            ha = ha * B + s[i];
            ha %= md;
            if (hash.find(ha) != hash.end()) {
                int check = hash[ha];
                // check for false positives (collisions) in the hash
                if (s[0] == s[n-check] && s[check-1] == s[n - 1]) {
                    len = check;
                }
            }
        }
        // return common prefix/suffix
        return s.substr(0, len);
    }
};