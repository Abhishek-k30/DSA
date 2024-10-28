class Solution {
public:
    int minOperations(int n) {
         int mid = n/2;
         int ops = 0;
         if(n%2 == 0){
             int midAvg = ((2*mid) + 1 + (2*(mid-1)) + 1)/2;
             
             for(int i = mid; i<n; i++){
                 ops+= (2*i) + 1 - midAvg;
             }
         }
         else{
             int midAvg = 2*mid+1;
             
             for(int i = mid+1; i<n; i++){
                 ops+= (2*i) + 1 - midAvg;
             }
         }
        
        return ops;
    }
};