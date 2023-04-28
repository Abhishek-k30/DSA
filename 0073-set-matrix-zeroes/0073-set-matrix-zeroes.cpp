class Solution {
public:
    void setMatrix(vector<vector<int>>& matrix , int i , int j){
        int n=matrix.size();
        int m= matrix[0].size();       
        int ind1=i , ind2=j;
                   while(ind1>=0){
                       matrix[ind1][ind2]=0;
                       ind1--;
                   }
                   ind1=i , ind2=j;
                   while(ind1<n){
                       matrix[ind1][ind2]=0;
                       ind1++;
                   }
                    ind1=i , ind2=j;
                   while(ind2>=0){
                       matrix[ind1][ind2]=0;
                       ind2--;
                   }
                   ind1=i , ind2=j;
                   while(ind2<m){
                       matrix[ind1][ind2]=0;
                       ind2++;
                   }
                   ind1=i , ind2=j;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m= matrix[0].size();
        vector<pair<int , int>> vp;
       for(int i=0 ; i<matrix.size() ; i++){
           for(int j=0 ; j<matrix[i].size() ; j++){
               if(matrix[i][j]==0){
                 vp.push_back({i , j});
               }
           }
       } 
        for(int i=0 ; i<vp.size() ; i++){
            setMatrix(matrix ,vp[i].first , vp[i].second);
        }
    }
};