class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st(arr.begin(), arr.end());
        unordered_map<int, int> mpp;
        int startRank = 1;
        for(auto &it: st){
            mpp[it] = startRank++;
        }
        
        vector<int> ans(arr.size());
        
        for(int i = 0; i<arr.size(); i++){
            ans[i] = mpp[arr[i]];
        }
        
        return ans;
    }
};