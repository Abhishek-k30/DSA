class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n!=original.size())return {};
        vector<vector<int>> ans(m, vector<int>(n));
        int check = original.size()/m;
        for(int i = 0; i<original.size(); i++){
            int rowIdx = i/check;
            int colIdx = i%n;
            ans[rowIdx][colIdx] = original[i];
        }
        return ans;
    }
};