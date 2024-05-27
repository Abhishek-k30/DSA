#define ll long long
class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<pair<ll, ll>> adj[n];
        for(auto &it :  edges){
            int node1= it[0];
            int node2= it[1];
            int wt = it[2];
            adj[node1].push_back({node2, wt});
            adj[node2].push_back({node1, wt});
        }
        
        
        vector<ll> dis(n, 1e14);
        
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, 
        greater<pair<ll, ll>>> pq;        //{wt, node}
        
        pq.push({0, 0});
        dis[0] = 0;
        while(!pq.empty()){
            ll wt = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            
            if(wt> dis[node])continue;
            for(auto it: adj[node]){
                if(it.second + wt < dis[it.first]){
                    dis[it.first] = it.second + wt;
                    pq.push({it.second + wt, it.first});
                }
            }
        }
        
        ll mx = dis[n-1];
        
         vector<ll> dis1(n, 1e14);
        
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, 
        greater<pair<ll, ll>>> pq1;        //{wt, node}
        
        pq1.push({0, n-1});
        dis1[n-1] = 0;
        while(!pq1.empty()){
            ll wt = pq1.top().first;
            ll node = pq1.top().second;
            pq1.pop();
            
            if(wt> dis1[node])continue;
            for(auto it: adj[node]){
                if(it.second + wt < dis1[it.first]){
                    dis1[it.first] = it.second + wt;
                    pq1.push({it.second + wt, it.first});
                }
            }
        }
        
        
        vector<bool> ans(edges.size(), false);
        int ind = 0;
        for(auto &it: edges){
            ll node1= it[0];
            ll node2= it[1];
            ll wt = it[2];
            
            if(dis[node1] +  dis1[node2] + wt == dis[n-1])ans[ind] = true;
            else if(dis[node2] + dis1[node1] + wt ==  dis[n-1])ans[ind] = true;
            
            ind++;
        }
        
        
        return ans;
    }
};