class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // for clockwise, first reverse the matrix and then swap it as (i,j)==(j,i)
        
        reverse(matrix.begin(), matrix.end());
        for(int i=0; i<matrix.size(); i++){
            for(int j=i+1; j<matrix[0].size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
    }
};

// TC=O(n), SC=O(1)