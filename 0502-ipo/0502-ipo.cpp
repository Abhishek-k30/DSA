class Solution {
public:
    static bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first != b.first) {
        return a.first < b.first;   
    } else {
        return a.second > b.second;  
    }
}

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = capital.size();
        vector<pair<int, int>> vp;      //{capital, profits}
        
        for(int i = 0; i<n; i++){
            vp.push_back({capital[i], profits[i]});
        }
        
        
        sort(vp.begin(), vp.end());
        
        int ans = 0;
        
        priority_queue<pair<int, int>> pq;
        int i = 0;
        while(k--){
            for( i; i<n; i++){
                if(w<vp[i].first)
                    break;
                pq.push({vp[i].second, vp[i].first});
            }
            if(pq.empty())
                break;
            int mx = pq.top().first;
            int cap = pq.top().second;
            pq.pop();
            
            cout<<mx<<" ";
            w+=mx;
            ans+=mx;
            
            
        }
        cout<<endl;
        
        return w;
    }
};