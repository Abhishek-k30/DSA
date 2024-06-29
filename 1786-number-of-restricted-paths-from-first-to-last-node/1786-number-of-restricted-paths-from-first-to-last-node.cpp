class Solution {
private:
    const int mod = 1e9 + 7;
    vector<int> dijkstarAlgo(int n , vector<pair<int, int>> adj[]){
        vector<int> dis(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>> pq;    //{weight, node}
        
        dis[n] = 0;
        pq.push({0, n});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            
            for(auto &it : adj[node]){
                int edgewt = it.second;
                int adjNode = it.first;
                
                if(wt + edgewt < dis[adjNode]){
                    dis[adjNode] = wt + edgewt;
                    pq.push({dis[adjNode], adjNode});
                }
            }
        }
        return dis;
    }
    int dfs(int node, vector<pair<int, int>> adj[], vector<int> & dis, vector<int> &dp){
        if(node == 1)
            return 1;
        if(dp[node] == -1){
            dp[node] = 0;
            
            for(auto &it : adj[node]){
                if(dis[it.first] > dis[node]){
                    dp[node] = (dp[node] + dfs(it.first, adj, dis, dp))%mod;
                }
            }
        }
        return dp[node];
    }
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[n+1];
        for(auto &it : edges){
            int node1 = it[0];
            int node2 = it[1];
            int wt = it[2];
            
            adj[node1].push_back({node2, wt});
            adj[node2].push_back({node1, wt});
        }
        
        vector<int> minDist = dijkstarAlgo(n, adj);
        
        vector<int> ways(n+1, -1);
        
        return dfs(n, adj, minDist, ways);
         
    }
};