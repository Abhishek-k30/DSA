class Solution {
private:
   
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt=0;
        long long dx[]={+1,-1,+0,+0};                      
        long long dy[]={+0,+0,+1,-1};                      
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                 if(vis[i][j] || grid2[i][j]==0)continue;
                 else{
                     queue<pair<int, int>> q;
                     vis[i][j]=1;
                     bool flag=true;
                     q.push({i, j});
                     while(!q.empty()){
                         int r=q.front().first;
                         int c=q.front().second;
                         q.pop();
                         if(grid1[r][c]==0)
                             flag=false;
                         
                         for(int k=0; k<4; k++){
                             int nrow= r+ dx[k];
                             int ncol= c+ dy[k];
                             
                             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid2[nrow][ncol]==1 && !vis[nrow][ncol]){
                                 vis[nrow][ncol]=1;
                                 q.push({nrow, ncol});
                             }
                         }
                     }
                     if(flag)cnt++;
                     }
                 }
            }
        
        
        return cnt;
    }
};