class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int, int>> adj[n+1];
        for(auto it: times){
            int node1= it[0];
            int node2= it[1];
            int time = it[2];
            
            adj[node1].push_back({node2, time});
        }
        
        vector<int> minTime(n+1, 1e9);
        minTime[k] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>> ,
        greater<pair<int, int>>> pq;                                  //{time, node}
        
        pq.push({0, k});
        
        while(!pq.empty()){
            int curTime = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            for(auto it: adj[node]){
                
                int edgeWt = it.second;
                int adjNode = it.first;
                
                if(curTime + edgeWt < minTime[adjNode]){
                    minTime[adjNode] = curTime + edgeWt;
                    pq.push({curTime + edgeWt , adjNode});
                }
                
            }
        }
        
        int mnTime =0;
        for(int i=1; i<=n; i++){
            if(minTime[i] == 1e9)
                return -1;
            
            mnTime= max(mnTime, minTime[i]);
        }
        
        return mnTime;
        
    }
};

//TC= O(ElogV)
//SC= O(2*n)