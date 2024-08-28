class Solution {
public:
    int solve(int idx, int prevMod, int &half, int &n, int &k, vector<int>&res, vector<int>&powers, vector<vector<int>> &dp){
        if(idx>half)return 0;
        if(idx == half){
            return prevMod==0;
        }
        if(dp[idx][prevMod]!=-1){
            return dp[idx][prevMod];
        }
        
        for(int d = 9; d>=0; d--){
            int newMod = prevMod;
            if((n&1) && (idx == half-1)){
                newMod+= (d*(powers[idx]))%k;
            }
            else{
                newMod+= (d*(powers[idx]))%k;
                newMod+= (d*(powers[n-idx-1]))%k;
            }
            
            newMod%=k;
            
            int flag = solve(idx+1, newMod, half, n, k, res, powers, dp);
            if(flag){
                res[idx] = d;
                break;
            }
        }
        
        if(res[idx]==-1)return dp[idx][prevMod] = 0;
        return dp[idx][prevMod] = 1;
    }
    string largestPalindrome(int n, int k) {
        int half = (n+1)/2;
        vector<int> powers(n, 0);
        powers[0] = 1%k;
        for(int i = 1; i<n; i++){
            powers[i] = (powers[i-1]*10)%k;
        }
        vector<vector<int>> dp(half, vector<int>(10, -1));
        vector<int> res(n, -1);
        int prevMod = 0;
        solve(0,prevMod, half,n, k, res, powers, dp);
        
        string ans(n,'0');
        for(int i = 0; i<half; i++){
            ans[i] = res[i] + '0';
            ans[n-i-1] = res[i] + '0';
        }
        return ans;
    }
};