class Solution {
private:
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int> & pathVis ){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it :  adj[node]){
            if(!vis[it]){
                if(dfs(it , adj, vis, pathVis))
                    return true;
            }
            else if(pathVis[it])
                return true;
        }
        
        pathVis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int V = numCourses ;
        vector<int> vis(V , 0);
        vector<int> pathVis(V , 0);
        
        // adjancy list
        vector<int> adj[V];
         for(int i=0 ; i< pre.size() ; i++){
             int a=pre[i][0];
             int b=pre[i][1];
             adj[a].push_back(b);
              
        }
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis))
                    return false;
            }
        }
        
        return true;
    }
};