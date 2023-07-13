class Solution {
public:
    vector<int> topoSort(int v, vector<vector<int>>& pre){
        vector<int> indegree(v , 0);
        vector<int> adj[v];
        for(int i=0 ; i< pre.size() ; i++){
             int a=pre[i][0];
             int b=pre[i][1];
             adj[a].push_back(b);
             indegree[b]++;
        }
         
       
        queue<int> q;
        for(int i=0 ; i<v; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return topo;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> topo=topoSort(numCourses ,prerequisites );
        if(topo.size()==numCourses){
            return true;
        }
        return false;
    }
};