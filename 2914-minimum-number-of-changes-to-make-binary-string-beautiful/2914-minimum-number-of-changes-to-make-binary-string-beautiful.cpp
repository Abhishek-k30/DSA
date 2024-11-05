class Solution {
public:
    int minChanges(string s) {
        // 0101011 ->
        int n = s.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum+= s[i]-'0';
        }
        
        int minOps = 0;
        int prevSum = 0;
        for(int i = 0; i<n-1; i+=2){
            prevSum = (s[i] - '0') + (s[i+1]-'0');
            int ZeroCnt = 2 - prevSum;
            
            minOps+=   (min(prevSum, ZeroCnt));
        }
        
        return minOps;
    }
};