class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>,
        greater<pair<double, pair<int, int>>>> pq;      //{val, {arr[i], arr[j]}}
        
        for(int i=0; i<n; i++){
            double cur = arr[i];
            for(int j=i+1; j<n; j++){
                double den = arr[j];
                pq.push({(cur/den), {cur, den}});
            }
        }
        
        int move = k-1;
        while(!pq.empty() && move--){
            pq.pop();
        }
        
        return {pq.top().second.first, pq.top().second.second};
    }
};