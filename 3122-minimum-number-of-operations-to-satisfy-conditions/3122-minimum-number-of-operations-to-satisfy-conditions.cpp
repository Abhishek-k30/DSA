class Solution {
private:
    int f(int col, int prev, int m ,int n,  vector<vector<int>> &grid, vector<vector<int>> &dp,
          vector<vector<int>> &pre){
        if(col==m)
            return 0;
        
        if(   dp[col][prev+1]!=-1)
            return dp[col][prev+1];
        int mini = 1e9; 
        for(int i=0; i<=9; i++){
            if(i==prev)
                continue;
            
            int cost = (n-pre[col][i]) + f(col+1, i, m, n , grid, dp, pre);
            
            mini = min(mini, cost);
        }
        
         
           return  dp[col][prev+1] = mini;
        
         
    }
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> pre(m, vector<int>(10, 0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                pre[i][grid[j][i]]++;
            }
        }
        
//         for(int i=0; i<m; i++){
//             for(int j=0; j<10; j++){
//                 cout<<pre[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
//         cout<<endl;
        
        
        vector<vector<int>> dp(m+1, vector<int>(11, -1));
        return f(0,-1, m, n, grid, dp, pre);
        
    }
};