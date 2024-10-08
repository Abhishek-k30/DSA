class Solution {
private:
    void dfs(int node, vector<int>&vis, vector<int> adj[]){
        vis[node] = 1;
        
        for(auto &it: adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj);
            }
        }
        
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                }
            }
        }
        
        int cnt = 0;
        
        vector<int> vis(n, 0);
        
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, vis, adj);
            }
        }
        
        return cnt;
    }
};