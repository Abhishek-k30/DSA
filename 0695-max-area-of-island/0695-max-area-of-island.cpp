class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        long long dx[]={+1,-1,+0,+0};                     
        long long dy[]={+0,+0,+1,-1}; 
        
         
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                 if(grid[i][j]==1){
                     grid[i][j]=0;
                     int cnt=1;
                     queue<pair<int, int>> q;
                     q.push({i,j});
                     while(!q.empty()){
                         pair<int, int> node= q.front();
                         q.pop();
                         for(int k=0; k<4; k++){
                             int nrow= node.first + dx[k];
                             int ncol= node.second + dy[k];
                             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                                 cnt++;
                                 q.push({nrow, ncol});
                                 grid[nrow][ncol]=0;
                             }
                         }
                     }
                     
                     ans=max(ans, cnt);
                     
                 }
            }
        }
        
        return ans;
    }
};