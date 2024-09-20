class Solution {
private:
    void computeLPS(string &pat, vector<int> &LPS){
            int M=pat.size();
            int len=0;
            LPS[0]=0;
            int idx=1;
            while(idx<M){
                if(pat[idx]==pat[len]){
                    len++;
                    LPS[idx]=len;
                    idx++;
                }
                else{
                    if(len!=0){
                        len=LPS[len-1];
                    }
                    else{
                        len=0;
                        idx++;
                    }
                }
            }
        }
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        string pat = s + "#" + rev;
        vector<int> LPS(2*n+1);
        computeLPS(pat, LPS);
        int maxi = LPS.back();
        
        return rev.substr(0,n-maxi) + s;
    }
};