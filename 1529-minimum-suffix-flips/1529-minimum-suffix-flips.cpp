class Solution {
public:
    int minFlips(string target) {
        int cnt = 0 , state = 0;
        for(auto &it: target){
            if(it-'0' !=state){
                cnt++;
                state = it-'0';
            }
        }
        
        return cnt;
    }
};