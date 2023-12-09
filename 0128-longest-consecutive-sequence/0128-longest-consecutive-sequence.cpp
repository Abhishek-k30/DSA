class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int mx=0;
        int lastValue=INT_MIN;
        int cnt=0;
        for(int i=0; i<n; i++){
             if(nums[i]-1 == lastValue){
                 cnt++;
                 lastValue = nums[i];
             }
            else if(nums[i]!= lastValue){
                cnt=1;
                lastValue=nums[i];
            }
            
            mx=max(mx, cnt);
            
        }
        
        return mx;
    }
};