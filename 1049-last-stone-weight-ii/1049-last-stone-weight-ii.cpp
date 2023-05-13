class Solution {
public:
//     int f(int ind, int curSum, vector<int> & stones,  vector<vector<int>> &dp){
//         int n= stones.size();
        
//         // Base Case
//         if(ind==n){
//             if(curSum<0)return INT_MAX;
//             return curSum;
//         }
        
//         // Memoiztion
//         if(curSum>0 && dp[ind][curSum]!=-1)return dp[ind][curSum];
//         if(curSum>0)dp[ind][curSum]=min(f(ind+1, curSum-stones[ind], stones, dp), f(ind+1,curSum+stones[ind], stones, dp));
//         return min(f(ind+1, curSum-stones[ind], stones, dp), f(ind+1,curSum+stones[ind], stones, dp));
    
//     }
    
    
    int sumDiv(int ind, int sum1, int sum2, vector<int> stones, vector<vector<int>> &dp){
        
        int n=stones.size();
        // Base Case
        if(ind==n)return abs(sum1-sum2);
        
        // Memoization
        if(dp[ind][sum1]!=-1)return dp[ind][sum1];
        
        return dp[ind][sum1]=min(sumDiv(ind+1,sum1+stones[ind], sum2, stones, dp), sumDiv(ind+1,sum1,sum2+stones[ind], stones, dp));
        
        
        
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n= stones.size();
        vector<vector<int>> dp(n,vector<int>(3000+1,-1));
        return sumDiv(0,0,0, stones, dp);
    }
};