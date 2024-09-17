class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m));
        
        queue<pair<pair<int, int>, int>> q;     //{{row, col}, time}
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }
        
        int dr[] = {0,-1,0,1};
        int dc[] = {1,0,-1,0};
        int maxTime = 0;
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            
            q.pop();
            
            maxTime = max(maxTime, time);
            
            for(int i = 0; i<4; i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                  && grid[nrow][ncol]== 1 && !vis[nrow][ncol] ){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, time+1});
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return maxTime;
    }
};