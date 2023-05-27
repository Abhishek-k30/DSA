class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string temp=s;
        reverse(temp.begin(), temp.end());
        
        //Longest palindrome subsequence will be the lcs of given string and its reverse :);
        
        int n=s.size();
        int m=temp.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==temp[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        
        return dp[n][m];
        
        
        
    }
};