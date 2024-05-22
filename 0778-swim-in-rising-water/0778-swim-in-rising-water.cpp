class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int mxTime=0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;
        mxTime = max(mxTime, grid[0][0]);
         pq.push({mxTime,{0, 0}});
        
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        
        vector<vector<int>> time(n, vector<int>(n, 1e9));
        
        while(!pq.empty()){
             int curTime = pq.top().first;
             int row = pq.top().second.first;
             int col = pq.top().second.second;
             pq.pop();
            
             if(row==n-1 && col==n-1)
                 return curTime;
            
            for(int k = 0; k<4; k++){
                int nrow = row + dr[k];
                int ncol = col + dc[k];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n
                  && max(curTime, grid[nrow][ncol]) < time[nrow][ncol]){
                    time[nrow][ncol] = max(curTime, grid[nrow][ncol]);
                    pq.push({max(curTime, grid[nrow][ncol]), {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};