class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, pair<int, int>> m;//storing first and last occurance of all char
        int n=s.size();
        for(int i=0; i<n; i++){
            if(m.find(s[i])==m.end()){
                m[s[i]]={i,i};
            }
            else{
                int val=m[s[i]].first;
                m[s[i]]={val, i};
            }
        }
        
        vector<int> ans;
        int lh=m[s[0]].first, rh=m[s[0]].second;
        for(int i=1; i<n; i++){
            int x=m[s[i]].first;
            int y=m[s[i]].second;
            
             if(x>rh){
                ans.push_back(rh-lh+1);
                lh=m[s[i]].first;
                rh=m[s[i]].second;
            }
            else if(y>rh){
                rh=m[s[i]].second;
            }
            
            if(i==n-1)ans.push_back(rh-lh+1);
             
        }
        
        return ans;
    }
};