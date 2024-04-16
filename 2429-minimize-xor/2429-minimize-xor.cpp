class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cntSetBits=0;
        for(int i=0; i<=31; i++){
            int bit= (num2>>i)&1;
            if(bit==1)cntSetBits++;
        }
        
        int mnNum=0;
        for(int i=31; i>=0; i--){
            int bit= (num1>>i)&1;
            if(bit==1 && cntSetBits>0){ 
                cntSetBits--;
                mnNum= mnNum | (1<<i);
            }
        }
        int idx=0;
        while(cntSetBits>0){
            int bit= (mnNum>>idx) &1;
            if(bit==0){
                cntSetBits--;
                 mnNum= mnNum | (1<<idx);
            }
            
            idx++;
        }
        
        return mnNum;
    }
};