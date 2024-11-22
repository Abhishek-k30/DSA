class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        unordered_map<string, int> mpp;
        int maxi = 0;
        
        for(int i = 0; i<n; i++){
            string s1 = "", s2 = "";
            for(int j = 0; j<m; j++){
                s1+=(matrix[i][j] + '0');
                
                if(matrix[i][j])s2+='0';
                else s2+='1';
            }
            
            mpp[s1]++;
            mpp[s2]++;
            
        }
        
        for(auto & it: mpp){
            maxi = max(maxi, it.second);
        }
        
        return maxi;
        
    }
};