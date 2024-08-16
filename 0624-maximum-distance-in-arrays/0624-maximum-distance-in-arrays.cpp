class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxi = 0;
        int lastmini = arrays[0][0];
        int lastmaxi = arrays[0].back();
        for(int i = 1; i<arrays.size(); i++){
            int curmaxi = arrays[i].back();
            int curmini = arrays[i][0];
            maxi = max({maxi, abs(curmaxi-lastmini), abs(lastmaxi-curmini)});
            lastmaxi = max(lastmaxi, curmaxi);
            lastmini = min(lastmini, curmini);
        }
        
        return maxi;
    }
};