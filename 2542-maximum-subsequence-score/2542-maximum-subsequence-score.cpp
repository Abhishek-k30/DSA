class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans=0;
        long long sum=0;
        
        vector<pair<int, int>> vp;
        for(int i=0; i<nums1.size(); i++){
            vp.push_back({nums2[i], nums1[i]});
        }
        
        sort(vp.rbegin(), vp.rend());
        
        priority_queue<int> pq;
        
        // Summing the greatest k-1 element
        for(int i=0; i<k-1; i++){
            sum+=(vp[i].second);
            pq.push(-vp[i].second);
        }
        
        for(int i=k-1; i<nums1.size(); i++){
            sum+=(vp[i].second);
            pq.push(-vp[i].second);
            
            // The minimum element will always be the kth term if we consider first k terms as the                 //vector is sorted in desecnding order
            ans=max(ans, sum*vp[i].first);
            
            // Decreasing the minimum element sum from total
            sum+=pq.top();
            pq.pop();
        }
        
        return ans;
    }
};

//TC= O(N*Log(N)+(N-K)*Log(K))
//SC=O(N+K)