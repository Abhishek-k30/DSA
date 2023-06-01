class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid.empty() || grid[0][0]!=0) return -1;
        int steps=0;
        queue<pair<int, int>> q;
        vector<int> dir{0,1,0,-1,0,1,1,-1,-1,1};
        if(grid[0][0]==0 && m==1 && n==1) return 1;
        q.push({0,0});
        grid[0][0]=1;
        while(!q.empty()){
            steps++;
            int size=q.size();
            for(int i=0; i<size; i++){
                 auto cord=q.front();
                 q.pop();
                for(int j=0; j<9; j++){
                    int nrow=cord.first+dir[j];
                    int ncol=cord.second+dir[j+1];
                    
                    if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol]!=1){
                        if(nrow==n-1 && ncol==m-1) return steps+1;
                        else{
                            q.push({nrow, ncol});
                            grid[nrow][ncol]=1;
                        }
                    }
                }
            }
            
        }
        
        return -1;
        
    }
};
//  TC=O(N+M) , SC=O(N+M);