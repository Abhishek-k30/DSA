class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        int xo_r=0;
        vector<int> xorPrefix(n);
        xorPrefix[0] = arr[0];
        for(int i=1; i<n; i++)xorPrefix[i] = arr[i]^xorPrefix[i-1];
        
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int cur = xorPrefix[j];
                
                if(i>0) cur = xorPrefix[j]^xorPrefix[i-1];
                if(cur==0){
                    cnt+=(j-i);
                }
            }
        }
        
        
      
        return cnt;
        
    }
};