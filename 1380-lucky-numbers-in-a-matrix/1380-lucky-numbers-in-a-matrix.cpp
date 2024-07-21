class Solution {
public:
  vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> colMax(m, 0);
    vector<int> rowMin(n, INT_MAX); 

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        rowMin[i] = min(rowMin[i], matrix[i][j]);
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        colMax[i] = max(colMax[i], matrix[j][i]);
      }
    }

    vector<int> lucky;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
          lucky.push_back(matrix[i][j]);
        }
      }
    }

    return lucky;
  }
};
