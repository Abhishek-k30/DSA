class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = n;
        
        set<int> st(nums.begin(), nums.end());
        
        vector<int> cur;
        for(auto &it: st)
            cur.push_back(it);
        
        int sz = cur.size();
        int diff = n-sz;
        int j = 0;
        for(int i=0; i<sz; i++ ){
            
            while(j<sz && cur[j]< cur[i] + n)
                j++;
            
            ops= min(ops, diff + sz-(j-i));
            
        }
        
        
        return ops;
        
        
        
        
        
    }
};