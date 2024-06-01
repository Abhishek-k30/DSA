#define ll long long
class Solution {
public:
    ll power(int N, int R, ll modulo){
        if(R==0)
            return 1;
        if(R==1)
            return (N%modulo);
        ll ans=1;
        ll know = power(N, R/2, modulo)%modulo;
        if(R%2){
            ans = (ans*N)%modulo;
        }
        return (ans*((know*know)%modulo))%modulo;
    }
    string subStrHash(string s, int p, int modulo, int k, int hashValue) {
        ll hs = 0;
        ll n = s.size();
        reverse(s.begin(), s.end());
        string ans = "";
        for(int i=0; i<n; i++){
            if(i<k){
                hs = (hs+((s[i]-'a'+1)*(power(p, k-i-1, modulo)))%modulo)%modulo;
                continue;
            }
            if(hs==hashValue){
                string cur = s.substr(i-k , k);
                reverse(cur.begin(), cur.end());
                ans=cur;
                
            }
            
            hs = (hs +  modulo-((s[i-k]-'a'+1)*power(p, k-1, modulo))%modulo)%modulo;
            hs=(hs*p)%modulo;
            hs = (hs  + (s[i]-'a'+1))%modulo;
            
        }
        if(hs==hashValue){
                string cur = s.substr(n-k , k);
                reverse(cur.begin(), cur.end());
                ans=cur;
                
        }
        
        return ans;
    }
};