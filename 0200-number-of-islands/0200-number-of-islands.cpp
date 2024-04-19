class Solution {
public: 
    void bfs(vector<vector<char>>& grid, int row , int col, vector<vector<int>>& vis){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        long long dx[]={+1,-1,+0,+0}; // 4 X directions
        long long dy[]={+0,+0,+1,-1}; 
        queue<pair<int, int>> q; // {row, col}
        q.push({row, col});
        while(!q.empty()){
            int curRow= q.front().first;
            int curCol= q.front().second;
            q.pop();
            
            
            for(int k=0; k<4; k++){
                int nrow= curRow + dx[k];
                int ncol= curCol + dy[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                    vis[nrow][ncol]=1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(grid, i, j, vis);
                }
            }
        }
        
        return cnt;
    }
};