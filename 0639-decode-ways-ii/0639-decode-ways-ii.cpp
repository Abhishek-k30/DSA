class Solution {
public:
    const int mod = 1e9+7;
    long long solve(int idx, int n, string s, vector<long long>&dp){
        if(idx>=n){
            return 1;
        }
        if(dp[idx]!=-1)return dp[idx];
        
        
        long long take1 = 0, take2 = 0;
        if(s[idx]=='*')take1 = (9*(solve(idx+1, n, s, dp)%mod))%mod;
        else if(s[idx]!='0')take1 = (solve(idx+1, n, s, dp))%mod;
        
        if(idx<n-1){
            if(s[idx]=='*'){
                if(s[idx+1]=='*'){
                    take2 = (15*solve(idx+2, n, s, dp))%mod;
                }
                else if(s[idx+1]<='6') take2 = (2*solve(idx+2, n, s, dp))%mod;
                else take2 = solve(idx+2, n, s, dp)%mod;
            }
            else if(s[idx]=='1'){
                if(s[idx+1]=='*'){
                    take2 = (9*solve(idx+2, n, s, dp))%mod;
                }
                else take2 = (solve(idx+2, n, s, dp))%mod;
            }
            else if(s[idx]=='2'){
                if(s[idx+1]=='*'){
                    take2 = (6*solve(idx+2, n, s, dp))%mod;
                }
                else if(s[idx+1]<='6')take2 = (solve(idx+2, n, s, dp))%mod;
            }
        }
        
        return dp[idx] = (take1%mod + take2%mod)%mod;
    }
    int numDecodings(string s) {
        
        int n = s.size();
        
//         vector<long long> dp(n, -1);
        
//         return solve(0, n, s, dp);
        
        vector<long long> dp(n+1, 0);
        dp[n] = 1;
        
        for(int i = n-1; i>=0; i--){
            if(s[i]=='*')dp[i]+= 9*(dp[i+1])%mod;
            else if(s[i] !='0')dp[i]+=(dp[i+1])%mod;
            
            if(i+1<n){
                if(s[i]=='*'){
                    if(s[i+1]=='*'){
                        dp[i] += (15*dp[i+2])%mod;
                    }
                    else if(s[i+1] <='6')dp[i] += (2*dp[i+2])%mod;
                    else dp[i] += dp[i+1]%mod;
                }
                else if(s[i]=='1'){
                    if(s[i+1] == '*'){
                        dp[i] += (9*dp[i+2])%mod;
                    }
                    else dp[i] += (dp[i+2])%mod;
                }
                else if(s[i]=='2'){
                    if(s[i+1] == '*'){
                        dp[i] += (6*dp[i+2])%mod;
                    }
                    else if(s[i+1]<='6')dp[i] += dp[i+2]%mod;
                }
            }
        }
        
        return dp[0]%mod;
    }
};