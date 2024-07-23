class Solution {
public:
    static bool comp(const pair<int, int> &a, const pair<int, int> &b){
        if(a.first!=b.first)
            return a.first < b.first;
        return a.second > b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto &it: nums)m[it]++;
        vector<pair<int, int>> vp;
        for(auto &it : m)vp.push_back({it.second, it.first});
        sort(vp.begin(), vp.end(), comp);
        
        vector<int> ans;
        for(auto &it : vp){
            int curNum = it.second;
            int freq = it.first;
            
            while(freq--)ans.push_back(curNum);
        }
        
        return ans;
        
    }
};