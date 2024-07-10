class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ops = 0;
        for(auto &it: logs){
            string curOps = it;
            int n = curOps.size();
            if(curOps[n-1]=='/' && curOps[n-2]=='.'){
                if(n>2 && curOps[n-3]=='.' && ops>0)
                    ops--;
            }
            else ops++; 
        }
        
        return ops;
    }
};