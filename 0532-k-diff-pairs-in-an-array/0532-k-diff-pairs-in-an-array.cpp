class Solution {
public:
    int findPairs(vector<int>& val, int k) {
        if(k==0){
            
            unordered_map<int, int> m;
            for(auto &it: val)
                m[it]++;
            
            int ans = 0;
            for(auto &it: m)
                if(it.second>1)
                    ans++;
            
            
            
            return ans;
            
            
        }
        unordered_set<int> uni(val.begin(), val.end());
        vector<int> nums;
        for(auto &it: uni)
            nums.push_back(it);
        
        
        int n = nums.size();
        
        
        
        sort(nums.begin(), nums.end());
        
        unordered_map<int, int> m;
        
        for(int i = 0; i<n; i++)
            m[nums[i]]++;
        
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            
            int cur = k + nums[i];
            
             m[nums[i]]--;
            if(m[nums[i]]<=0)
                m.erase(nums[i]);
            
            
            if(m.find(cur)!=m.end()){
                ans ++;
                
                
                 
            }
            
           
        }
        
        return ans;
    }
};