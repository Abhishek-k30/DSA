class Solution {
public:
    long long f(long long ind,vector<vector<int>>& questions , vector<long long> &dp ){
        long long n=questions.size();
        
        // Base Case
        if(ind<0 || ind>=n)return 0;
        if(ind==n-1)return questions[ind][0];
        
        // Memoization
        if(dp[ind]!=-1)return dp[ind];
        
        // Not Pick
        long long notPick=f(ind+1, questions, dp);
        
        // Pick
        long long  Pick=questions[ind][0]+f(ind+questions[ind][1]+1,questions, dp);
        
        // Return maximum
        return dp[ind]=max(Pick, notPick);
        
        
    }
    long long mostPoints(vector<vector<int>>& questions) {
        long long n=questions.size();
        vector<long long> dp(n+1,-1);
        return f(0, questions, dp);
    }
};
// TC=O(N), SC=O(N)+O(N)