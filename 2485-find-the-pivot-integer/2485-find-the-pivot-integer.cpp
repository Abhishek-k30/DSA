class Solution {
public:
    using ll=long long;
    int pivotInteger(int n) {
        ll sum=(1LL*n*(n+1))/2;
        ll sum2=0;
        for(int i=0; i<n; i++){
            sum2+=(i+1);
            sum-=(i);
            if(sum2==sum)return (i+1);
        }
        return -1;
    
    }
};