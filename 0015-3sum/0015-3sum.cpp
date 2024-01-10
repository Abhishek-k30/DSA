class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>> vs;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int tar= -nums[i];
            int front=i+1;
            int rear=n-1;
            while(front<rear){
                int sum= nums[front] + nums[rear];
                if(sum<tar)front++;
                else if(sum>tar)rear--;
                else{
                    vs.insert({nums[i], nums[front], nums[rear]});
                    front++;
                    rear--;
                }
            }
        }
        
        for(auto it: vs)
            ans.push_back(it);
        
        return ans;
    }
};