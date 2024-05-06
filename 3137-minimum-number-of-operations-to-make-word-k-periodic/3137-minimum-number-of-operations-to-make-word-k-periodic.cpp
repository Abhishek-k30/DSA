class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        map<string, int> m;
        int ind=0;
        for(int i=0; i<word.size()/k; i++){
            string s="";
            for(int j=0; j<k; j++){
                s+=word[ind+j];
                 
            }
            m[s]++;
            ind+=k;
        }
        
        int mx=0;
        int total=word.size()/k;
        for(auto it: m){
             mx=max(it.second, mx);
        }
        
        return total-mx;
    }
};