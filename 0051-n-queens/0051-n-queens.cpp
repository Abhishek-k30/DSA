class Solution {
private:
    bool isSafe(int row, int col, int n, vector<string> &board){
        // left upper diagonal
        
        int curRow = row, curCol = col;
        while(curRow >=0 && curCol >=0){
            if(board[curRow][curCol]=='Q')
                return false;
            
            curRow--;
            curCol--;
        }
        
        // left
        curRow = row, curCol = col;
        while(curCol>=0){
            if(board[curRow][curCol]=='Q')
                return false;
            
            curCol--;
        }
        
        // left down diagonal
        curRow = row, curCol = col;
         while(curRow <n && curCol >=0){
            if(board[curRow][curCol]=='Q')
                return false;
            
            curRow++;
            curCol--;
        }
        
        return true;
        
    }
public:
    void backtrack(int col, int n,  vector<string> &board, vector<vector<string>> &ans){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row<n; row++){
            if(isSafe(row, col, n,  board)){
                board[row][col] = 'Q';
                backtrack(col+1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        
        for(int i = 0; i<n; i++){
            board[i] = s;
        }
        
        backtrack(0, n, board, ans);
        return ans;
        
        
    }
};