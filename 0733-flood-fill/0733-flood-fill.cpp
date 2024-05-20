class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        
        int initColor=image[sr][sc];
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        //bfs
        queue<pair<int, int>> q;        //{row, col}
        q.push({sr, sc});
        image[sr][sc]=color;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int k=0; k<4; k++){
                int nrow = row + dr[k];
                int ncol = col + dc[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initColor
                  && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    image[nrow][ncol]=color;
                    q.push({nrow, ncol});
                }
            }
        }
        
        
        return image;
        
    }
};