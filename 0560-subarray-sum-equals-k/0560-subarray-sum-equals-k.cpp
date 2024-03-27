class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        // calculating prefix
        for(int i=1; i<n; i++){
            prefix[i]= prefix[i-1]+ nums[i];
        }
        
        unordered_map<int, int> m;
        int ans=0;
        for(int i=0; i<n; i++){
            if(prefix[i]==k)
                ans++;
            if(m.find(prefix[i]-k)!=m.end())
                ans+=m[prefix[i]-k];
            
            m[prefix[i]]++;
        }
        
        return ans;
    }
};