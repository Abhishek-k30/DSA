class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int maxi = 0;
        unordered_map< int, int> mpp;
        for(auto &it : edges){
            mpp[it[0]]++;
            mpp[it[1]]++;
            
            maxi = max({maxi, it[0], it[1]});
        }
        
        int centerFreq = maxi - 1;
        for(auto &it : mpp){
            if(it.second == centerFreq)
                return it.first;
        }
        
        return 0;
    }
};