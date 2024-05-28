class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> cur(n);
        for(int i =0; i<n; i++){
            int val = abs((int)(s[i]-t[i]));
            cur[i] = val; 
        }
        
        for(int i=0; i<n; i++)cout<<cur[i]<<" ";
        cout<<endl;
        int l = 0, ans = 0, sum=0;
        
        for(int r=0; r<n; r++){
            sum += cur[r];
            
            while(l<=r && sum > maxCost){
                sum-= cur[l];
                l++;
            }
            
            ans=max(ans, r-l+1);
        }
        
        return ans;
    }
};