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
    void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans,
              vector<int> &left, vector<int> &upperDiag, vector<int> & lowerDiag){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row<n; row++){
            if(left[row] == 0 && lowerDiag[row+col] == 0 && upperDiag[n-1 + col-row] == 0){
                board[row][col] = 'Q';
                left[row] = 1;
                lowerDiag[row+col] = 1;
                upperDiag[n-1+col-row] = 1;
                solve(col+1, n, board, ans, left, upperDiag, lowerDiag);
                board[row][col] = '.';
                left[row] = 0;
                lowerDiag[row+col] = 0;
                upperDiag[n-1 + col-row] = 0;
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
        
        //backtrack(0, n, board, ans);
        
        vector<int> left(n, 0), upperdiagonal(2*n-1, 0), lowerdiagonal(2*n-1, 0);
        solve(0, n, board, ans, left, upperdiagonal, lowerdiagonal);
        return ans;
        
        
    }
};

//TC = O(n!)
//SC = O(n*n)