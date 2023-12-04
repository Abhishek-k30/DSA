class Solution {
public:
    double myPow(double x, int n) {
        
        if(n<0){
            x=1/x;
        }
        
        long num=labs(n);
        
        double pow=1;
        
        while(num!=0){
            
            if((num&1)!=0){
                pow*=x;
            }
            
            x*=x;
            
            num/=2;
        }
        
        return pow;
    }
};

//TC=O(log2(n)), SC=O(1)