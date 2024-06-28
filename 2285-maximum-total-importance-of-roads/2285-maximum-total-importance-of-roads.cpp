class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        for(auto &it : roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        priority_queue<int> pq;      //{node}
        for(int i =0; i<n; i++){
            pq.push(adj[i].size());
        }
        
        long long ans = 0;
        long long maxi = n;
        while(!pq.empty()){
            int indegree = pq.top();
            pq.pop();
            
            ans += (maxi * ((1LL) * indegree));
            maxi--;
        }
                    
        return ans;
    }
};