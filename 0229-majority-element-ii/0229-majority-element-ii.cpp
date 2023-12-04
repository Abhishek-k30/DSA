class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int num1=-1, num2=-1, cnt1=0,cnt2=0;
        for(auto it: nums){
            if(it==num1)cnt1++;
            else if(it==num2)cnt2++;
            else if(cnt1==0){
                num1=it;
                cnt1++;
            }
            else if(cnt2==0){
                num2=it;
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        
        
        int count1=0, count2=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==num1)count1++;
            else if(nums[i]==num2)count2++;
        }
        if(count1> nums.size()/3)ans.push_back(num1);
        if(count2> nums.size()/3)ans.push_back(num2);
        
        return ans;
        
        
        
    }
};

// TC=O(n), SC=O(1)