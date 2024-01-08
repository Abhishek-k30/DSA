class Solution {
public:
    int sm(int n){
        int sum=0;
        while(n>0){
            int r=n%10;
            sum+= r*r;
            n/=10;
        }
        
        return sum;
    }
    bool isHappy(int n) {
        int slow=n, fast=sm(n);
        
        while(slow!=fast){
            slow=sm(slow);
            fast=sm(sm(fast));
        }
        
        return slow==1;
    }
};