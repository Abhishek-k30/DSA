class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> minEffort(n, vector<int>(m, 1e9));
        
        
        //4 direction traversal
        int dr[] = {1,0,-1,0};
        int dc[] = {0,1,0,-1};
        
        //bfs
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;         //{effort, {row, col}}
        
        pq.push({0, {0, 0}});
        minEffort[0][0] = 0;
        
        while(!pq.empty()){
            int effort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            if(row==n-1 && col == m-1)
                return effort;
            
            for(int k=0; k<4; k++){
                
                int nrow = row + dr[k];
                int ncol = col + dc[k];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m ){
                    int curEffort = max(abs(heights[row][col]-heights[nrow][ncol]), effort);
                    
                    if(curEffort < minEffort[nrow][ncol]){
                        minEffort[nrow][ncol] = curEffort;
                        pq.push({curEffort, {nrow, ncol}});
                    }
                }
            }
            
            
        }
        
        return -1;
    }
};

//TC=O(ElogV)
//SC=O(N*M)