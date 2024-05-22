class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0)return -1;
        vector<vector<int>> dist(n, vector<int> (n, 1e9));
        
        //bfs
        queue<pair<int, pair<int, int>>> q;         //{dist,{row, col}}
        q.push({1,{0,0}});
        dist[0][0] = 1;
        
        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            //traverse in 8 directions
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    
                    int nrow = row + i;
                    int ncol = col + j;
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n 
                      && grid[nrow][ncol]==0 && dis + 1 < dist[nrow][ncol]){
                        dist[nrow][ncol] = 1 + dis;
                        if(nrow==n-1 && ncol == n-1)
                            return  dis + 1 ;
                        q.push({dis + 1 , {nrow, ncol}});
                    }
                }
            }
        }
        
        return  (dist[n-1][n-1]==1e9? -1 : dist[n-1][n-1]);
    }
};