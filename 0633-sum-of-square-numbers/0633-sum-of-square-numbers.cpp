class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0, r = sqrt(c);
        if(r*r<c)r++;
        
        while(l<=r){
            long long sum = l*l + r*r;
            if(sum==c)
                return true;
            if(sum>c)
                r--;
            else l++;
        }
        
        return false;
    }
};