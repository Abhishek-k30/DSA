bool comp(vector<int> &a, vector<int> &b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        
        vector<int> v= intervals[0];
        int ans=-1;
        for(auto it: intervals){
            if(v[1]>it[0])ans++;
            else v=it;
        }
        
        return ans;
    }
};
// TC=O(nlogn), SC=O(n)