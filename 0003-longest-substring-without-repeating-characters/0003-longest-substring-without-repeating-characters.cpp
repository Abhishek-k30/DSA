class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        
        int len = 0;
        int left = 0;
        for(int i = 0; i<s.size(); i++){
            if(mpp.find(s[i])!=mpp.end()){
                left = max(mpp[s[i]]+1, left);
            }
            
            mpp[s[i]] = i;
            len = max(len, i-left+1);
              
        }
        
        return len;
    }
};