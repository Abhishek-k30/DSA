class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> s;
        for(int i=0; i<9; i++){
            int temp_cnt=0;
            for(int j=0; j<9; j++){
                if(board[j][i]!='.'){
                    temp_cnt++;
                    s.insert(board[j][i]);
                }
            }
            if(temp_cnt!=s.size())return false;
            s.clear();
        }
        s.clear();
        
        for(int i=0; i<9; i++){
            int temp_cnt4=0;
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    temp_cnt4++;
                    s.insert(board[i][j]);
                }
            }
            if(temp_cnt4!=s.size())return false;
            s.clear();
        }
        
        int mult=1;
         unordered_set<char> s1,s2,s3;
            int temp_cnt1=0;
            int temp_cnt2=0;
            int temp_cnt3=0;
        for(int i=0; i<9; i++){
           
            for(int j=0; j<=2; j++){
                if(board[i][j]!='.'){
                    temp_cnt1++;
                    s1.insert(board[i][j]);
                }
            }
             for(int j=3; j<=5; j++){
                if(board[i][j]!='.'){
                    temp_cnt2++;
                    s2.insert(board[i][j]);
                }
            }
            
             for(int j=6; j<=8; j++){
                if(board[i][j]!='.'){
                    temp_cnt3++;
                    s3.insert(board[i][j]);
                }
            }
             
            if((i+1)%3==0){
                //cout<<temp_cnt1<<" "<<s1.size()<<endl;
                if(temp_cnt1!=s1.size() || temp_cnt2!=s2.size() || temp_cnt3!=s3.size()){
                    return false;
                }
             temp_cnt1=0;
             temp_cnt2=0;
             temp_cnt3=0;
            
            s1.clear();
            s2.clear();
            s3.clear();
                
               
                 
                
            }
             
        }
        
        return true;
    }
};