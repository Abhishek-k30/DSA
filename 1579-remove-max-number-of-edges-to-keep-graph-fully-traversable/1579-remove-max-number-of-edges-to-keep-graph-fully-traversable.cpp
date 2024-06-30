class DisjointSet {
public:
    vector<int> rank, parent, size; 
 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        sort(edges.begin(), edges.end());
        reverse(edges.begin(), edges.end());   
        
        DisjointSet ds1(n+1), ds2(n+1);
 
        int cnt1 = 0 , cnt2 = 0;
        
        for(auto &it : edges){
            int type = it[0];
            int u = it[1];
            int v = it[2];
            bool f = false;
            if(type== 1 || type == 3){
            if(ds1.findUPar(u) == ds1.findUPar(v)){
                cnt1++;
                f = true;
            }
            else ds1.unionBySize(u,v);
            }
            if(type == 2  || type == 3){
                
            
            
               if(ds2.findUPar(u) == ds2.findUPar(v) && (!f )){
                cnt2++;
               }
              else ds2.unionBySize(u,v);
            
            }
        }
            
                bool aliceNotReach = false;
        bool bobNotReach = false;
        
         int cntC = 0;
            for(int i = 1; i<=n; i++){
                if(ds1.parent[i] == i)
                    cntC++;
            }
            
            if(cntC >1)aliceNotReach = true;
        
          cntC = 0;
            for(int i = 1; i<=n; i++){
                if(ds2.parent[i] == i)
                    cntC++;
            }
            
            
            if(cntC >1)bobNotReach = true;
        
        if(aliceNotReach || bobNotReach)
        return -1;
        return cnt1 + cnt2;
    }
};