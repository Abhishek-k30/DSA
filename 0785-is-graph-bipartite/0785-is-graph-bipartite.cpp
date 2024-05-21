class Solution {
private:
    bool check(int node, vector<vector<int>>& graph,  vector<int> &color , int cur ){
        color[node] = cur;
        for(auto it: graph[node]){
            if(color[it]==-1){
                if( check(it, graph, color , !cur) ==false)
                    return false;
            }
            else if(color[it] == color[node])
                return false;
        }
        
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V,-1);
        for(int i=0; i<V; i++){
             if(color[i]==-1){
                 if(check(i, graph, color, 0)==false)
                     return false;
             }
        }
        return true;
    }
};