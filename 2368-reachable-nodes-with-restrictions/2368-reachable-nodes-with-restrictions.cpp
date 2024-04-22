class Solution {
public:
    void dfs(vector<int>  adj[], unordered_set<int> &s , int node, vector<int>& vis){
        if(s.find(node)!=s.end())return;
        vis[node]=1;
        for(auto adjacent: adj[node]){
            if(!vis[adjacent]) 
            dfs(adj, s, adjacent, vis);
        }
        
        return;
        
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int> s(restricted.begin(), restricted.end());
        vector<int> adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n, 0);
        dfs(adj, s, 0, vis);
        int ans=0;
        for(int i=0; i<vis.size(); i++){ans+=vis[i];
                                        cout<<vis[i]<<" ";}
        cout<<endl;
         
        return ans;
    }
};