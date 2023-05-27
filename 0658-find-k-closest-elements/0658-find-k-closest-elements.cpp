class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
         priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        for(int i=0; i<arr.size(); i++){
            int a=abs(arr[i]-x);
            pq.push({a, arr[i]});
        }
        vector<int> ans;
        for(int i=0; i<k; i++){
            auto it=pq.top();
            int t=it.second;
            pq.pop();
            ans.push_back(t);
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};