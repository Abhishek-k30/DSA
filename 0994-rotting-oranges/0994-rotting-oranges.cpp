class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q; // {{row, col}, time}
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({{i, j}, 0});
                }
            }
        }
        
        int mxTime=0;
        // bfs
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col= q.front().first.second;
            int time= q.front().second;
            mxTime=max(mxTime, time);
            q.pop();
            
            for(int k=0; k<4; k++){
                int nrow= row+dr[k];
                int ncol= col+dc[k];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                  vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({{nrow , ncol}, time+1});
                }
            }
            
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j])
                    return -1;
            }
        }
        
        return mxTime;
    }
};