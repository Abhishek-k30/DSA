class Solution {
public:
    int maxProfitAssignment(vector<int>& dif, vector<int>& profit, vector<int>& worker) {
        int n = dif.size();
        vector<pair<int, int>> vp;
        for(int i = 0; i<n; i++){
            vp.push_back({dif[i], profit[i]});
        }
        
        sort(vp.begin(), vp.end());
        sort(dif.begin(), dif.end());
        
        vector<int> pre(n, 0);
        pre[0] = vp[0].second;
        
        for(int i = 1; i<n; i++){
            pre[i] = max(pre[i-1] , vp[i].second);
        }
        
        int sum = 0;
        
        sort(worker.begin(), worker.end());
        
        for(int i = 0; i<worker.size(); i++){
            int talent = worker[i];
            int idx = upper_bound(dif.begin(), dif.end(), talent) - dif.begin();
//             while(idx>=0 && dif[idx]>talent)idx--;
            
//             if(idx>=0 && idx<n)
            if(idx-1>=0)
                sum+= pre[idx-1];
        }
        
        return sum;
    }
};