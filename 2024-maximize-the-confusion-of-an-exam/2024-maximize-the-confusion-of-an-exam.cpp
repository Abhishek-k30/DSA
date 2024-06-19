class Solution {
private:
    bool good(string answerKey, int k , int sz){
        int t = 0, f = 0;
        int n = answerKey.size();
        
        for(int i = 0; i<sz; i++){
            if(answerKey[i] == 'T')
                t++;
            else f++;
        }
        
        int idx = 0;
        int mx = max(t, f), mn = min(t, f);
        if(mn<=k)return true;
        
        for(int i= sz; i<n; i++){
            if(answerKey[i]=='T')t++;
            else f++;
            
            if(answerKey[idx] == 'T')t--;
            else f--;
            
            idx++;
            
            mn = min(t, f);
            if(mn<=k)
                return true;
        }
        
        return false;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        
        int l = 0 , r = n;
        int ans = 0;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(good(answerKey, k, mid)){
                ans = max(ans, mid);
                l = mid + 1;
            }
            else r = mid-1;
        }
        
        return ans;
    }
};