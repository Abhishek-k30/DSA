class Solution {
public:
    
    int minMoves(int target, int maxDoubles) {
        int start = 1;
        int ops = 0;
        while(target!=1){
            if(target%2==1 ){
                target--;
                ops++;
            }
            else{
                if(maxDoubles>0){
                    target/=2;
                    maxDoubles--;
                    ops++;
                }
                else{
                     ops+= (target-1);
                    break;
                }
            }
        }
            
        
        return ops;
    }
};