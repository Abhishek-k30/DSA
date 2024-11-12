class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        sort(items.begin(), items.end());
        vector<int> maxPre(n);
        maxPre[0] = items[0][1];
        
        for(int i = 1; i<n; i++){
            maxPre[i] = max(maxPre[i-1], items[i][1]);
        }
        vector<int> ans(queries.size());
        
        for(int i = 0; i<queries.size(); i++){
            int cur = queries[i];
            int max_beauty = 0;
            int l = 0, r = n-1;
            
            while(l<=r){
                int mid = l + (r-l)/2;
                
                if(items[mid][0]<= cur){
                    max_beauty = max(max_beauty, maxPre[mid]);
                    l = mid+1;
                }
                else r = mid-1;
            }
            
            ans[i] = max_beauty;
        }
        
        return ans;
    }
};