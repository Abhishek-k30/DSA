class Solution {
private:
    int mapp(int num, vector<int>& mapping ){
        int ans ;
        string cur = to_string(num);
        for(auto &it : cur){
            char c = mapping[it-'0'] + '0';
            it = c;    
        }
        ans = stoi(cur);
        return ans;
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int , int> mpp;
        vector<pair<int, pair<int, int>>> vp;
        for(int i = 0; i<nums.size(); i++){
            int mapped = mapp(nums[i], mapping);
            vp.push_back({mapped, {nums[i], i}});
            mpp[nums[i]] = mapped;
        }
        
        sort(vp.begin(), vp.end(), [&](pair<int, pair<int, int>>a, pair<int, pair<int, int>> b){
            if(mpp[a.second.first] == mpp[b.second.first]){
                return a.second.second < b.second.second;
            }
            return a.first < b.first;
        });
        
        vector<int> ans;
        for(auto &it : vp)ans.push_back(it.second.first);
        return ans;
    }
};