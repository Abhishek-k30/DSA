class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int, double>> adj[n+1];
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<double> dist(n, (double)0.0);
        dist[start_node] =  1.0;
        priority_queue<pair<double, int>> pq; //{prob, node}
        
        pq.push({(double)1.0, start_node});
        while(!pq.empty()){
            int node = pq.top().second;
            double prob = pq.top().first;
            pq.pop();
            
            for(auto it: adj[node]){
                double edgeProb = it.second;
                int adjNode = it.first;
                
                if(edgeProb * prob > dist[adjNode]){
                    dist[adjNode] = edgeProb*prob;
                    pq.push({edgeProb*prob, adjNode});
                }
            }
         
       }
        
        return dist[end_node];
    }
};