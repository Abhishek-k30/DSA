#include<bits/stdc++.h>
class TreeAncestor {
public:
    vector<vector<int>> sparseTable1;
    TreeAncestor(int n, vector<int>& parent) {  //tc = o(nlogn)
        vector<vector<int>> sparseTable(n, vector<int>(20, 0));
        for(int i=0; i<n; i++)sparseTable[i][0] = parent[i];
        
        //precomputation
        for(int j=1; j<20; j++){
            for(int i=0; i<n; i++){
                if(sparseTable[i][j-1]==-1)sparseTable[i][j] = -1;
                else sparseTable[i][j] = sparseTable[sparseTable[i][j-1]][j-1];
            }
        }
        
        swap(sparseTable, sparseTable1);
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0; i<20; i++){
            if(k& (1<<i)){
                node = sparseTable1[node][i];
                if(node==-1)return -1;
            }
        }
        
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */