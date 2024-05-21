class Solution {
private:
    void dfs(int row, int col , vector<vector<int>> &grid, vector<vector<int>> & vis ){
        vis[row][col]=1;
        int n = grid.size();
        int m = grid[0].size();
        
        // 4- direction traversal
        
        int dr[] = {-1, 0, 1 ,0};
        int dc[] = {0, 1, 0, -1};
        
        for(int k=0; k<4; k++){
            int nrow = row + dr[k];
            int ncol = col + dc[k];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
              && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow, ncol, grid, vis);
            }
        }
        
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // 1st col
        for(int i=0; i<n; i++){
            if(grid[i][0]==1)
                dfs(i, 0, grid, vis);
        }
        
        //last col
        for(int i=0; i<n; i++){
            if(grid[i][m-1])
                dfs(i, m-1, grid, vis);
        }
        
        //1st row
        for(int j=0; j<m; j++){
            if(grid[0][j])
                dfs(0, j, grid, vis);
        }
        
        //last row
        for(int j=0; j<m; j++){
            if(grid[n-1][j])
                dfs(n-1, j, grid, vis);
        }

        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && vis[i][j]==0)
                    count++;
            }
        }
        
        return count;
        
    }
};
//TC= O(N*M) , SC= O(N*M)