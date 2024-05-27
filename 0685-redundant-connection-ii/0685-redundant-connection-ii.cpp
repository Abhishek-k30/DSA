#include <vector>
using namespace std;

class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return false;
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
            rank[rootY] += rank[rootX];
        } else {
            parent[rootY] = rootX;
            rank[rootX] += rank[rootY];
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int numNodes = edges.size(), edgeRemoved = -1, edgeMakesCycle = -1;
        vector<int> parent(numNodes + 1, 0);

        for (int i = 0; i < numNodes; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (parent[v] != 0) {
                edgeRemoved = i;
                break;
            } else {
                parent[v] = u;
            }
        }

        UnionFind uf(numNodes);
        for (int i = 0; i < numNodes; i++) {
            if (i == edgeRemoved)
                continue;
            int u = edges[i][0];
            int v = edges[i][1];
            if (!uf.unionSets(u, v)) {
                edgeMakesCycle = i;
                break;
            }
        }

        if (edgeRemoved == -1) {
            return edges[edgeMakesCycle];
        }

        if (edgeMakesCycle != -1) {
            int v = edges[edgeRemoved][1];
            int u = parent[v];
            return {u, v};
        }

        return edges[edgeRemoved];
    }
};
