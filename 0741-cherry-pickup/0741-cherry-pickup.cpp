class Solution {
public:
    int dp[51][51][51];
    int f(int r1, int c1, int r2, vector<vector<int>>& grid){
        int n=grid.size();
        int c2=r1+c1-r2;
        if(r1<0 || r1>=n || c1<0 || c1>=n || r2<0 || r2>=n || c2<0 || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return -1e5;
        }
        
        if(r1==n-1 && c1==n-1)return grid[r1][c1];
        
        
        // Memoization 
        
        if(dp[r1][c1][r2]!=-1)return dp[r1][c1][r2];
        int temp=0;
        
        // if both are in same cell
        if(r1==r2 && c1==c2)temp+=grid[r1][c1];
        else temp+=(grid[r1][c1]+grid[r2][c2]);
        
        int a=f(r1+1,c1, r2+1, grid);
        int b=f(r1+1,c1,r2,grid);
        int c=f(r1, c1+1,r2, grid);
        int d=f(r1, c1+1,r2+1,grid);
        
        temp+=max(max(a,b), max(c,d));
        
        return dp[r1][c1][r2]=temp;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return max(0,f(0,0,0,grid));
    }
};

// TC=O(N*N) SC=O(N*N*N+N);