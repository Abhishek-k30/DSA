class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        int dx[]={+1,-1,+0,+0};                     
        int dy[]={+0,+0,+1,-1}; 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    for(int k=0; k<4; k++){
                        int nrow= i+dx[k];
                        int ncol=j+dy[k];
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0)
                            ans++;
                        else if(nrow<0 || nrow>=n || ncol<0 || ncol>=m)
                            ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};