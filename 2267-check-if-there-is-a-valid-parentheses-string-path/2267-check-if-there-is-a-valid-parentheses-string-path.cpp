class Solution {
public:
    int n, m;
    int dr[2] = {0,1};
    int dc[2] = {1,0};
    bool dfs(int row, int col, int openBracket,  vector<vector<char>>& grid, vector<vector<vector<int>>> &dp){
        if(row == n-1 && col == m-1){
            if(openBracket == 0){
                return true;
            }
            return false;
        }
        
        if(dp[row][col][openBracket]!=-1)return dp[row][col][openBracket];
        bool pathFound = false;
        for(int k = 0; k<2; k++){
            int nrow = row + dr[k];
            int ncol = col + dc[k];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                if(grid[nrow][ncol]=='('){
                   pathFound   = dfs(nrow, ncol, openBracket+1, grid, dp);
                }
                else if(grid[nrow][ncol]==')' && openBracket>0){
                    pathFound = dfs(nrow, ncol, openBracket-1, grid, dp);
                }
                
                if(pathFound)break;
            }    
        }
        
        return dp[row][col][openBracket] = pathFound;
        
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        if(grid[0][0] == ')')return false;
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(205,-1)));
        return dfs(0, 0, 1, grid, dp);
    }
};