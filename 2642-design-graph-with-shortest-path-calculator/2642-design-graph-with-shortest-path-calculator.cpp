class Graph {
public:
    vector<vector<pair<int,int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto &it : edges){
            adj[it[0]].push_back({it[1], it[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        
        int n = adj.size();
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>> pq;    //{weight, node}
        
        dis[node1] = 0;
        pq.push({0, node1});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            
            for(auto &it : adj[node]){
                if(it.second + wt < dis[it.first]){
                    dis[it.first] = it.second + wt;
                    pq.push({dis[it.first], it.first});
                }
            }
        }
        
        if(dis[node2]== INT_MAX)
            return -1;
        return dis[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */