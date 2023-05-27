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
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        //return f(n-1, m-1, text1, text2, dp);
        // Tabulation
        
        
         for(int i=1; i<=n; i++){
             for(int j=1; j<=m; j++){
                 
                 if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                 else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
             }
         }
        
        return dp[n][m];
        
            
    }
};

// TC=O(N*M), SC=O(N*M)