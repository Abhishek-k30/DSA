class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorElem = nums[0];
        int cnt = 1;
        
        for(int i = 1; i<nums.size(); i++){
            if(cnt == 0){
                majorElem = nums[i];
                cnt = 1;
            }
            else if(majorElem == nums[i])cnt++;
            else cnt--;
        }
        
        return majorElem;
    }
};