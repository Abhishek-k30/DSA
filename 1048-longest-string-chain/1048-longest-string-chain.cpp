class Solution {
private:
    bool compare(string &s1, string &s2){
        int n = s1.size();
        int m = s2.size();
        if( n-m!=1)
            return false;
        
        int l = 0 , r= 0 ;
        int cnt = 0;
        while(l<n){
            if(r<m && s1[l] == s2[r])
            {
                l++;
                r++;
            }
            else l++;
        }
        
        if(l==n && r==m)
            return true;
        return false;
        
    }
    int f(int ind, int prev, vector<string> &words, vector<vector<int>> &dp){
        
        if(ind== words.size())
            return 0;
        
        if(dp[ind][prev+1]!=-1)
            return dp[ind][prev+1];
        
        int notTake = f(ind+1, prev, words, dp);
        int take = 0;
        if(prev==-1 || compare(words[ind], words[prev]))
            take = 1 + f(ind+1, ind, words, dp);
        
        return dp[ind][prev+1] = max(take, notTake);
    }
public:
    static bool comp(string &s1, string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        
         sort(words.begin(), words.end(), comp);
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
         
        return f(0, -1, words, dp);
    }
};