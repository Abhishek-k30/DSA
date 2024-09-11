class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diff = start^goal;
        int setBitCnt = 0;
        for(int i = 0; i<=31; i++){
            if(diff&(1LL<<i))setBitCnt++;
        }
        
        return setBitCnt;
    }
};