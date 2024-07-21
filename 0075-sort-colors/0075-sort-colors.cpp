class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;
        for(auto &it: nums){
            if(it==0)
                zero++;
            else if(it==1)
                one++;
            else two++;
        }
        
        int idx = 0;
        while(zero--)nums[idx++] = 0;
        while(one--)nums[idx++] = 1;
        while(two--)nums[idx++] = 2;
    }
};