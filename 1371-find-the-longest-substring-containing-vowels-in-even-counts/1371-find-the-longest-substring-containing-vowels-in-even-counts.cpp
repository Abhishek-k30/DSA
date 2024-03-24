class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<int, int> m;
        m[0]=-1;
        int mask=0;
        string v="aeiou";
        int res=0;
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<5; j++){
                if(s[i]==v[j]){
                    mask^=(1<<j);
                    break;
                }
            }
            
            cout<<mask<<" ";
            if(m.find(mask)==m.end()){
                m[mask]=i;
            }
            
            res=max(res, i-m[mask]);
        }
        
        cout<<endl;
        return res;
    }
};