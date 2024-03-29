class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int cnt=0;
        // unordered_set<int> st;
        int mn=nums[0];
        //st.insert(mn);
        for(int i=1; i<n; i++){
            if(nums[i]-mn<=k  ){
                continue;
            }
            else{
                cnt++;
                
                mn=nums[i];
            }
        }
        
         
        return ++cnt;
    }
};