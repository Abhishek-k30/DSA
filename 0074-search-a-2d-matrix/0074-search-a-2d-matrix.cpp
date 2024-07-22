class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int low = 0, high = n*m-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            int curElement = matrix[mid/m][mid%m];
            
            if(curElement == target)
                return true;
            else if(curElement< target) low = mid + 1;
            else high = mid - 1;
        }
        
        return false;
    }
};