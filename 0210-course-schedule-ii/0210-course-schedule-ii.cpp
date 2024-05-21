class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        int V = numCourses;
        
        // adjancy list
        vector<int> adj[V];
         for(int i=0 ; i< pre.size(); i++){
            int a=pre[i][0];
            int b=pre[i][1];
            adj[b].push_back(a);
            
        }
        
        vector<int> topo;
        vector<int> indegree(V, 0);
        
        for(int i=0; i<V; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
       
         
        
        //bfs
        queue<int> q;
        
        for(int i=0; i<V; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto it :  adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        
        if(topo.size() == V)
            return topo;
        return {};
        
    }
};

//TC= O(V+E)
//SC= O(2*N)