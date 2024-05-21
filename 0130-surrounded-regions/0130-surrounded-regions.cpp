class Solution {
public:
    void dfs(int row, int col, vector<vector<char>> board , vector<vector<int>>& vis ){
        vis[row][col]=1;
        int n = board.size();
        int m = board[0].size();
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = { 0, 1, 0,-1};
        
        for(int k=0; k<4; k++){
            int nrow = row + dr[k];
            int ncol = col + dc[k];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
              && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow, ncol, board, vis);
            }
        }
         
        
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        // 1st col
        for(int i=0; i<n; i++){
            
            if(board[i][0]=='O')
                dfs(i, 0, board, vis);
        }
        
        // last col
        for(int i=0; i<n; i++){
            if(board[i][m-1]=='O')
                 dfs(i, m-1, board , vis);
        }
        
        // 1st row
        for(int j=0; j<m; j++){
            if(board[0][j]=='O')
                dfs(0, j, board, vis);
        }
        
        // last row
        for(int j=0; j<m; j++){
            if(board[n-1][j]=='O')
                dfs(n-1, j, board, vis);
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};