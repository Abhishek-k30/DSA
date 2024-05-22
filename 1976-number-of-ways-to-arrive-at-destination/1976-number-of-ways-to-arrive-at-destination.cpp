class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        
        for(auto it : roads){
            int node1 = it[0];
            int node2 = it[1];
            int time =  it[2];
            
            adj[node1].push_back({node2, time});
            adj[node2].push_back({node1, time});
        }
        
        vector<long long> time(n, 1e15);
        vector<long long> ways(n, 0);
        
        long long mod = (long long)(1e9 + 7);
        
        time[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, 
        greater<pair<long long,long long>>> pq;     //{time, node}
        
        pq.push({0, 0});
        
        
        while(!pq.empty()){
            long long curTime = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                long long edgeWt = it.second;
                long long adjNode = it.first;
                
                if(curTime + edgeWt < time[adjNode]){
                    time[adjNode] = curTime + edgeWt;
                    ways[adjNode] = ways[node]%mod;
                    pq.push({curTime + edgeWt, adjNode});
                }
                else if( curTime + edgeWt == time[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod; 
                }
            }
        }
        
        return ways[n-1] % mod;
    }
};
//TC= O(ElogV)
//SC= O(n)