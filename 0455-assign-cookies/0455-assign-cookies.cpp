class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(),s.end());
        
        int cnt = 0;
        int l = 0;
        for(int i = 0; i<s.size(); i++){
            if(l>=g.size())
                break;
            if(g[l]<=s[i]){
                cnt++;
                l++;
            }
        }
        return cnt;
    }
};