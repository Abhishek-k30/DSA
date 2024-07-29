class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
            for(int j = 0; j<n; j++){
                if(j <i){
                    if(rating[i] >  rating[j]){
                        x1++;
                    }
                    else y1++;
                }
                else if(j>i){
                    if(rating[i] >  rating[j]){
                        x2++;
                    }
                    else y2++;
                }
            }
             
            ans+= x1*y2 + x2*y1;
        }
         
        return ans;
    }
};