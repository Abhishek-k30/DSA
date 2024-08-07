class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1= -1, num2 =-1, cnt1 = 0, cnt2 = 0;
        
        for(int i = 0; i<n; i++){
            if(num1 == nums[i])cnt1++;
            else if(num2 == nums[i])cnt2++;
            else if(cnt1==0){
                num1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                num2 = nums[i];
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        
        int count1 = 0, count2 = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]==num1)count1++;
            else if(nums[i] == num2)count2++;
        }
        
        vector<int> ans;
        if(count1 > n/3)ans.push_back(num1);
        if(count2 > n/3)ans.push_back(num2);
        
        return ans;
    }
};