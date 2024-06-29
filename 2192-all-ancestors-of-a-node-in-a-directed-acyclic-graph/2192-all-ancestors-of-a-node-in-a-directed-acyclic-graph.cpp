class Solution {
private:
    void dfs(int node, int parent,  vector<int> adj[], vector<int> &vis, vector<vector<int>> &cur ){
        vis[node] = 1;
        if(node!=parent)
            cur[node].push_back(parent);
        for(auto &it : adj[node]){
            if(!vis[it]){
                dfs(it, parent, adj, vis, cur);
            }
        }
        
        return;
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto &it : edges)
            adj[it[0]].push_back(it[1]);
        
        vector<vector<int>> ancestor(n);
        for(int i = 0; i<n; i++){
            vector<int> vis(n, 0);
            
            dfs(i, i, adj, vis, ancestor );
            
             
        }
        return ancestor;
    }
};