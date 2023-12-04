class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int high= n*m-1, low=0;
        while(low<=high){
            int mid= low+ (high-low)/2;
            int mid_value= matrix[mid/m][mid%m];
            
            // found
            if(mid_value==target)return true;
            
            //Not found
            else if(mid_value<target) low=mid+1;
            else high=mid-1;
        }
        
        return false;
        
    }
};

// TC= O(n*m), SC=O(1)