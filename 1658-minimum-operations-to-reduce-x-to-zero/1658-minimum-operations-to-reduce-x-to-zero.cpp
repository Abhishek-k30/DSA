class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        
        int ans = n+1;
        
        prefix[0] = nums[0];
        suffix[0] = nums[n-1];
        
        if(prefix[0] ==  x)
            return 1;
        if(suffix[0]== x)
            return 1;
        
        for(int i = 1; i<n; i++ ){
            prefix[i] = nums[i] + prefix[i-1];
            suffix[i] = nums[n-i-1] + suffix[i-1];
            
            if(prefix[i] == x)
                ans = min(ans, i+1);
            if(suffix[i] == x)
                ans = min(ans, i+1);
        }
        
        for(int i = 0; i<n; i++){
            int curVal = prefix[i];
            int req = x - curVal;
            
            if(req<=0)
                continue;
            
            int idx = lower_bound(suffix.begin(), suffix.end() - (i+1), req) - suffix.begin();
            
            if(idx>=0 && idx<= (n-i-1) && suffix[idx] == req){
                 
                ans =  min(ans, (i+1+ idx +1));
            }
        }
        
         
        if(ans== n+1)
            return -1;
        return ans;
    }
};