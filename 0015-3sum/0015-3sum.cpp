class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i<n; i++){
            int tar = -nums[i];
            int low  =  i+1;
            int high = n-1;
            
            while(low<high){
                int sum  = nums[low] + nums[high];
                
                if(sum == tar){
                    st.insert({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                }
                else if(sum > tar)high--;
                else low++;
            }
            
        }
        
        for(auto &it : st)
            ans.push_back(it);
        
        return ans;
    }
};