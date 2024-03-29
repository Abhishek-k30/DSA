class Solution {
public:
    int balancedString(string s) {
        int n=s.size();
        unordered_map<char, int> cnt;
        for(int i=0; i<n; i++)cnt[s[i]]++;
        int l=0,ans=1e9, k=n/4;
        for(int r=0; r<n; r++){
            cnt[s[r]]--;
            while(l<n && cnt['Q']<=k && cnt['W']<=k && cnt['E']<=k && cnt['R']<=k){
                ans=min(ans, r-l+1);
                cnt[s[l]]++;
                l++;
            }
            
        }
        
        return ans;
    }
};