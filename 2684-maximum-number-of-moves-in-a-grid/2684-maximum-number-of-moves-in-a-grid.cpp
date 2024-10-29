class Solution {
public:
    int n , m, maxCnt = 0;
    int dr[3] = {-1,0,1};
    int dc[3] = {1,1,1};
    void dfs(int row, int col, int cnt, vector<vector<int>> &vis, vector<vector<int>>& grid){
        
        vis[row][col] = 1;
        
        maxCnt = max(maxCnt, cnt);
        
        for(int k = 0; k<3; k++){
            int nrow = row + dr[k];
            int ncol = col + dc[k];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
              !vis[nrow][ncol] && grid[nrow][ncol] > grid[row][col]){
                dfs(nrow, ncol, cnt+1, vis, grid);
            }
        }
        
    }
    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++){
            
            dfs(i,0,0,vis,grid);
        }
        
        return maxCnt;
    }
};