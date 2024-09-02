class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(int i = 0; i<chalk.size(); i++){
            sum+=1LL*chalk[i];
        }
        k%=sum;
        for(int i = 0; i<chalk.size(); i++){
            if(chalk[i]>k){
                return i;
            }
            else {
                k-=chalk[i];
            }
        }
        
        return 0;
    }
};