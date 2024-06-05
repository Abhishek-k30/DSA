class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int  n = nums.size();
        unordered_map<int, int> mpp;
        set<int> st;
        for(int i = 0; i<n ; i++){
            mpp[nums[i]]++;
        }
        
        unordered_map<int, int> mpp2;
        for(int  i =0; i<n; i++){
            mpp2[nums[i]]++;
            if(mpp.find(nums[i])!=mpp.end())mpp[nums[i]]--;
            
            int freq1 = mpp2[nums[i]];
            int freq2 = mpp[nums[i]];
            
            int sz1= i+1;
            int sz2 = n-sz1;
            
            if(freq1*2> sz1 && freq2*2> sz2)
                return i;
            
            if(mpp[nums[i]]<=0)mpp.erase(nums[i]);
        }
        
        return -1;
        
    }
};