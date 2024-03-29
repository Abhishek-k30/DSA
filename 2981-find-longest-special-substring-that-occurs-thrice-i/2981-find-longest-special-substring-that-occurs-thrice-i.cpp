class Solution {
public:
    int maximumLength(string s) {
        int n=s.size();
        unordered_map<char, vector<int>> m;
        int cnt=0;
        char prev=s[0];
        for(int i=0; i<n; i++){
            if(s[i]==prev)cnt++;
            else{
                m[prev].push_back(cnt);
                cnt=1;
                prev=s[i];
            }
        }
        m[prev].push_back(cnt);
        
        int ans=0;
        
        for(auto [k, v]: m){
            int l1=0, l2=0, l3=0;
            for(auto e : v){
                if(l1<e){l3=l2; l2=l1; l1=e;}
                else if(l2<e){l3=l2; l2=e;}
                else if(l3<e)l3=e;
            }
            
            if(l1==l2 && l1>l3)l2--;
            if(l1+l2+l3>=3)ans=max({ans, l1-2, l2});
        }
        
      
        ans=(ans> 0 ? ans : -1);
        return ans;
        
    }
};