class Solution {
public:
    double distance(double x, double y){
        return sqrt(x*x + y*y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        vector<vector<int>> ans;
        priority_queue<pair<double, vector<int>> , vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>> > pq;
        for(int i=0; i<n; i++){
            double dist=distance(points[i][0], points[i][1]);
            pq.push({ dist, points[i]});
        }
        
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};