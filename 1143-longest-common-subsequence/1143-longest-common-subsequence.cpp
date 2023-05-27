class Solution {
public:
    int f(int index1, int index2, string &s, string &t, vector<vector<int>> &dp){
        
        // Base Case
        if(index1<0 || index2<0)return 0;
        
        // Memoization
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        
        //Match
        if(s[index1]==t[index2]) return 1+f(index1-1, index2-1, s, t, dp);
        
        // Not Match
        return dp[index1][index2]=max(f(index1-1, index2, s, t, dp), f(index1, index2-1, s, t, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, text1, text2, dp);
            
    }
};