class Solution {
public:
    void dfs(vector<int> adj[] , vector<int> &vis, int src){
        vis[src]=1;
        for(auto it: adj[src]){
            if(!vis[it]){
                dfs(adj, vis, it);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        dfs(adj, vis, source);
        if(vis[destination]==1)return true;
        return false;
    }
};