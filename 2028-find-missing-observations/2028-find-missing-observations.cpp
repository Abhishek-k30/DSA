class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum1 = accumulate(rolls.begin(), rolls.end(),0);
        int reqSum = (mean)*(n+m) - sum1;
        
        if(n*6<reqSum || n>reqSum)
            return {};
        int val = reqSum/n;
        int rem = reqSum%n;
        
        int idx = 0;
        vector<int> ans(n, val);
        while(idx<n && rem){
            ans[idx]++;
            rem--;
            idx++;
        }
        return ans;
    }
};