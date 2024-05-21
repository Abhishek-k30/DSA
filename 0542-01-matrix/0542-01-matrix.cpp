class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dis(n, vector<int>(m, 0));
        
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        //bfs
        queue<pair<pair<int, int>, int>> q;       //{{row, col}, distance}
        for(int i=0; i<n; i++){
            for(int j=0; j<m ; j++){
                if(mat[i][j]==0){
                    q.push({{i, j}, 0});
                    vis[i][j]=1;
                }   
            }
        }
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            
            dis[row][col]=dist;
            
            //traversal in all 4 directions
            for(int k=0; k<4; k++){
                int nrow = row + dr[k];
                int ncol = col + dc[k];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                  && !vis[nrow][ncol] && mat[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({{nrow, ncol},dist+1});
                }
            }
        }
        
        
        return dis;
    }
};