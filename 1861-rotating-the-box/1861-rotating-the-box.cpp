class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        
        vector<vector<char>> rotated_box;
        for(int i = 0; i<m; i++){
            vector<char> temp;
            for(int j = n-1; j>=0; j-- ){
                temp.push_back(box[j][i]);
            }
            rotated_box.push_back(temp); 
        }
        
        for(int i = 0; i<n; i++){
            for(int j = m-1; j>=0; j--){
                if(rotated_box[j][i]=='#'){
                    int colidx = j;
                    while(colidx+1<m && 
                          (rotated_box[colidx+1][i]!='*' && rotated_box[colidx+1][i]!='#')){
                        rotated_box[colidx][i] = '.';
                        colidx++;
                    }
                    
                    rotated_box[colidx][i] = '#';
                }
            }
        }
        
        
        return rotated_box;
    }
};