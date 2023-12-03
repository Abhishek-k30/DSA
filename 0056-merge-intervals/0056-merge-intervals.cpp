class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            
            if(ans.empty()){
                ans.push_back(intervals[i]);
            }
            
            else{
                
                vector<int> &v= ans.back();
                
                // Overlapping
                if(v[1]>= intervals[i][0]){
                    v[1]=max(intervals[i][1], v[1]);
                }
                
                // Non overlapping
                else{
                    ans.push_back(intervals[i]);
                }
                
                
                
                
            
            
            }
        }
            
            return ans;
    }
};

// TC=O(n), SC=O(2*n)