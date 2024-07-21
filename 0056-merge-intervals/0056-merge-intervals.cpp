class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> mergedInterval;
        
        sort(intervals.begin(), intervals.end());
        
        for(auto &it : intervals){
            if(mergedInterval.empty())
                mergedInterval.push_back(it);
            else{
                vector<int> &v = mergedInterval.back();
                if(v[1]>=it[0]){
                    v[1] = max(v[1], it[1]);
                }
                else mergedInterval.push_back(it);
            }
        }
        
        return mergedInterval;
    }
};