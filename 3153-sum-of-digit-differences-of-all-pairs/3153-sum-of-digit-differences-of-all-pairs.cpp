#define ll long long
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v(n, vector<int>(10,-1));
        
        for(int i = 0; i<n; i++){
            int cur = nums[i];
            int idx = 0;
            while(cur>0){
              int r = cur%10;
                
               v[i][idx] = r;
               idx++;
                cur/=10;
            }
        }
        
        
//         for(int i=0; i<n; i++){
//             for(int j=0; j<10; j++){
//                 cout<<v[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
//          cout<<endl;
        
        ll ans = 0;
        for(int i = 0 ; i<10; i++){
            unordered_map<int, ll> m;
            for(int j=0; j<n; j++){
                if(v[j][i]!=-1)m[v[j][i]]++;
            }
            ll cnt = n;
            for(int j=0; j<n; j++){
                if(v[j][i]!=-1){
                    ll cur = cnt;
                    cur -=  m[v[j][i]];
                    cnt--;
                    m[v[j][i]]--;
                    if(m[v[j][i]]<0)m.erase(v[j][i]);
                    ans+=cur;
                }
            }
        }
        
        return ans;
       
        
    }
};