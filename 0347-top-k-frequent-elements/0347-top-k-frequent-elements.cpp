class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        vector<pair<int, int>> vp;
        for(auto it: m){
            vp.push_back({it.second, it.first});
        }
        sort(vp.begin(), vp.end(), greater<pair<int,int>>());
        for(int i=0; i<k; i++){
            ans.push_back(vp[i].second);
        }
         
        
        return ans;
        
        
    }
};