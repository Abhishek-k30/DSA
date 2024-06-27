class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int ans = INT_MIN;
        
        for(int i = 0; i<n; i++){
            int center = vals[i];
            
            priority_queue<int> pq;
            for(auto &it : adj[i]){
                pq.push(vals[it]);
            }
            
            int size = k;
            while(size-- && !pq.empty()){
                if(pq.top()>0)center += pq.top();
                pq.pop();
                
            }
            
            ans = max(ans, center);
        }
        
        return ans;
    }
};