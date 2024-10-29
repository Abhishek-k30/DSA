class Solution {
public:
    int n , m;
    int dr[3] = {-1,0,1};
    int dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>>&memo){
        
        if(memo[row][col]!=-1)return memo[row][col];
        int moves = 0;
        
        for(int k = 0; k<3; k++){
            int nrow = row + dr[k];
            int ncol = col + 1;
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
              grid[nrow][ncol] > grid[row][col]){
                moves = max(moves , 1 + dfs(nrow, ncol, grid, memo));
            }
        }
        
        return memo[row][col] = moves;
    }
    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<int>> memo(n, vector<int>(m, -1));
        int res = 0;
        
        for(int i = 0; i<n; i++){
            
           res = max(res, dfs(i,0,grid, memo));
        }
        
        return res;
    }
};