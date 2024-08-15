class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int remFive = 0, remTen=0;
        for(int i = 0; i<bills.size(); i++){
            int cur = bills[i];
            if(cur == 5)remFive++;
            else if(cur==10){
                if(remFive<=0)return false;
                remFive--;
                remTen++;
            }
            else if(cur == 20){
               if((remFive>=3) || (remFive>=1 && remTen>=1)){
               if(remTen <=0){
                   remFive-=3;
               }
               else{
                    remFive--;
                    remTen--;
               }
               }
               else return false;
            }
        }
        
        return true;
    }
};