class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int begin=0, end=n*m-1;
        
        // Applying binarySearch
        // Here we are treating 2D matrix as sorted list. To convert 2D matrix in single array we are         // using  mid/m which gives row index and mid%m which gives column index
        
        
        while(begin<=end){
            
            int mid=begin+(end-begin)/2;
            
            if(matrix[mid/m][mid%m]==target)return true;
            else if(matrix[mid/m][mid%m]<target)begin=mid+1;
            else end=mid-1;
        }
        
        return false;
    }
};
// TC=O(log(M*N)), SC=O(1);