class Solution {
private:
    bool isSubsequence(string &a, string &b){
        int l = 0, r = 0;
        while(l<a.size() && r<b.size()){
            if(a[l]==b[r]){
                l++;
                r++;
            }
            else r++;
        }
        
        return (l>=a.size());
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt = 0;
        unordered_map<string, int> mpp;
        for(int i = 0; i<words.size(); i++){
            if(mpp.find(words[i])!=mpp.end()){
                cnt++;
            }
            else if(isSubsequence(words[i], s)){
                cnt++;
                mpp[words[i]]++;
            }
            
            
        }
        
        return cnt;
    }
};