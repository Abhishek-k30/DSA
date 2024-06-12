#define ll long long
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rect) {
        int n = rect.size();
        
        unordered_map<double, ll> m;
        
        for(int i=0; i<n; i++){
            double num = rect[i][0];
            double den = rect[i][1];
            
            double div = num/den;
            
            m[div]++;
        }
        
        ll ans = 0;
        
        for(int i=0; i<n; i++){
            double num = rect[i][0];
            double den = rect[i][1];
            
            double div = num/den;
            
            m[div]--;
            if(m[div]<=0)
                m.erase(div);
            
            if(m.find(div)!=m.end()){
                ans+= m[div];
            }
        }
        
        return ans;
    }
};