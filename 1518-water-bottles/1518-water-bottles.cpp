class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = numBottles;
        int extra = 0;
        while(numBottles>0){
            int cur = (numBottles + extra)/numExchange;
            extra = (numBottles + extra)%numExchange;
            numBottles = cur;
            if(numBottles>0)
                cnt+=numBottles;
            else break;
            
        }
        
        return cnt;
    }
};