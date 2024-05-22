class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int, int>> adj[n];
        
        for(int i=0; i<flights.size(); i++){
            int node1= flights[i][0];
            int node2= flights[i][1];
            int cost = flights[i][2];
            
            adj[node1].push_back({node2, cost});
        }
        
        vector<int> minCost(n, 1e9);
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;     //{stops, {curCity, cost}}
        
        pq.push({0, {src, 0}});
        minCost[src] = 0;
        
        while(!pq.empty()){
            int stop = pq.top().first;
            int curCity = pq.top().second.first;
            int curCost = pq.top().second.second;
            pq.pop();
            
            if(stop > k)
                continue;
            
            for(auto it: adj[curCity]){
                if(curCost + it.second < minCost[it.first]){
                    minCost[it.first] = curCost + it.second ;
                    pq.push({stop + 1, { it.first, curCost + it.second }});
                }
            }
        }
        
        if(minCost[dst] == 1e9)
            return -1;
        return minCost[dst];
    }
};

//TC= O(ElogV)
//SC= O(2*n)