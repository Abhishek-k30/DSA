class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> m;
        int mx=0;
        for(int i=0; i<tasks.size(); i++){
            m[tasks[i]]++;
            mx=max(mx, m[tasks[i]]);
        }
        int ans= (mx-1)*(n+1);
        for(auto it: m){
            if(it.second==mx)ans++;
        }
        
        
        return max((int)tasks.size(), ans);
        
        
        
    }
};