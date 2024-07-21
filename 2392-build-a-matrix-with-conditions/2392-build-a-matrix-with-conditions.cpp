class Solution {
private:
    vector<int> toposort(int v, vector<int> adj[]){
        vector<int> indegree(v, 0);
        for(int i = 0; i<v; i++){
            for(auto &it : adj[i])
                indegree[it]++;
        }
        
        queue<int> q;
        for(int i = 0; i<v; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto &it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
            
        }
        
        return topo;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        int n1 = rowConditions.size();
        int n2 = colConditions.size();
        
        vector<int> adj1[k+1], adj2[k+1];
        
        for(auto &it : rowConditions){
            adj1[it[0]].push_back(it[1]);
        }
        
        for(auto &it : colConditions){
            adj2[it[0]].push_back(it[1]);
        }
        
        vector<int> topo1 = toposort(k+1, adj1);
        vector<int> topo2 = toposort(k+1, adj2);
        
        if(topo1.size()!=k+1 || topo2.size()!=k+1)
            return {};
        else{
            vector<vector<int>> matrix(k, vector<int> (k, 0));
            unordered_map<int, int> m1, m2;
            for(int i = 1; i<topo1.size(); i++){
                m1[topo1[i]] = i-1;
            }
            for(int i = 1; i<topo2.size(); i++){
                m2[topo2[i]] = i-1;
            }
            
            for(int i = 1; i<=k; i++){
                matrix[m1[i]][m2[i]] = i;
            }
            
           return matrix;
        }
    }
};