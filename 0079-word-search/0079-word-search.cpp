class Solution {
private:
    bool func(int row, int col, int idx, string target,vector<vector<int>> &vis,
            vector<vector<char>>& board){
        if(idx == target.size()){
            return true;
        }
        int dr[] = {1,0,-1,0};
        int dc[] = {0,1,0,-1};
        
        for(int i = 0; i<4; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            
            if(nrow>=0 && nrow< board.size() && ncol>=0 && ncol< board[0].size() && !vis[nrow][ncol]
              && board[nrow][ncol] == target[idx]){
                vis[row][col] = 1;
                 
                if(func(nrow, ncol, idx+1,  target, vis, board))
                    return true;
                
                vis[row][col] = 0;
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(word[0] ==  board[i][j] && !vis[i][j]){
                    if( func(i, j, 1,   word, vis, board))
                        return true;
                }
            }
        }
        
        return false;
    }
};