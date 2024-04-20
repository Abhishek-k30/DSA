class Solution {
private:
    void bfs(vector<vector<int>> &land, int row, int col , vector<vector<int>> &vis, vector<vector<int>> &ans){
        int n=land.size();
        int m=land[0].size();
        vis[row][col]=1;
        long long dx[]={+1,-1,+0,+0};                   
        long long dy[]={+0,+0,+1,-1}; 
        vector<pair<int, int>> vp;
        queue<pair<int,int>> q;
        q.push({row, col});
        while(!q.empty()){
            int r= q.front().first;
            int c= q.front().second;
            q.pop();
            vp.push_back({r,c});
            for(int k=0; k<4; k++){
                int nrow = r+ dx[k];
                int ncol = c+ dy[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && land[nrow][ncol]==1){
                    q.push({nrow, ncol});
                    vp.push_back({nrow, ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        sort(vp.begin(), vp.end());
        if(vp.size()<1)return;
        ans.push_back({vp[0].first, vp[0].second, vp.back().first, vp.back().second});
        
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && land[i][j]==1){
                    bfs(land, i , j, vis, ans);
                }
            }
        }
        
        return ans;
    }
};