class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        // flags for tracking zero of first row and column
        bool flagR=false, flagC=false;
        
        for(int i=0; i<n; i++){
             if(matrix[i][0]==0)flagR=true;
        }
        
        for(int j=0; j<m; j++){
            if(matrix[0][j]==0)flagC=true;
        }
        
        
        // if any cell contains zero, we will make the left edge cell and topmost cell zero
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=matrix[0][j]=0;
                }
            }
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        
        if(flagR){
            for(int i=0; i<n; i++){
                matrix[i][0]=0;
            }
        }
        if(flagC){
            for(int j=0; j<m; j++){
                matrix[0][j]=0;
            }
        }
    }
};
// TC=O(n*m), SC=O(1)