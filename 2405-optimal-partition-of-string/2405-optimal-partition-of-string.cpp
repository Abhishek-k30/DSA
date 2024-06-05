class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        int cnt = 1, flag = 0;
        for(int i=0; i<n; i++){
            int num = s[i] - 'a';
            if(flag & (1<<num)){
                cnt++;
                flag = 0;
            }
           
            flag |= (1<<num);
        }
        
        return cnt;
    }
};