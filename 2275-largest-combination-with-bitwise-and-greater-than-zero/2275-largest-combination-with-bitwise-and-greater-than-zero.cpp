class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        vector<vector<int>> bits(n, vector<int>(24,0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<24; j++){
                bits[i][j] = ((candidates[i]&(1<<j))>0 ? 1 : 0);
            }
        }
        
        int maxlen = 0;
        for(int col = 0; col<24; col++){
            int onesCnt = 0;
            for(int row = 0; row<n; row++){
                onesCnt+=bits[row][col];
            }
            
            maxlen = max(maxlen, onesCnt);
        }
    
        
        return maxlen;
        
    }
};