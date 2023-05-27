class Solution {
public:
    int f(int index1, int index2, string &s , string &t, vector<vector<int>> &dp  ){
        
        //Base Case
        if(index1<0)return index2+1;
        if(index2<0)return index1+1;
        
        // Memoization
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        
        
        //Match
        if(s[index1]==t[index2])
            return dp[index1][index2]= f(index1-1, index2-1, s, t, dp);
        
        // Not Match
        return dp[index1][index2]=  1+ min({f(index1-1, index2, s, t, dp), f(index1, index2-1, s, t, dp), f(index1-1, index2-1, s, t, dp)});
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return f(n-1, m-1, word1, word2, dp);
        
    }
};