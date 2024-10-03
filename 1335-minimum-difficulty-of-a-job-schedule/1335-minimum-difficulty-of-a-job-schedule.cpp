class Solution {
public:
    int memo[301][11];
    int solve(vector<int>&jd, int n, int idx, int d){
        if(d==1){
            int curMax = jd[idx];
            
            for(int i = idx; i<n; i++){
                curMax = max(curMax, jd[i]);
            }
            
            return curMax;
        }
        
        
        if(memo[idx][d]!=-1)return memo[idx][d];
        int res = INT_MAX;
        int maxD = jd[idx];
        
        for(int i = idx; i<=n-d; i++){
            maxD = max(maxD, jd[i]);
            
            int curRes = maxD + solve(jd, n, i+1, d-1);
            
            res = min(res, curRes);
        }
        
        return memo[idx][d] = res;
    }
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        
        memset(memo, -1, sizeof(memo));
        if(n<d){
            return -1;
        }
        
        return solve(jd, n, 0, d);
    }
};