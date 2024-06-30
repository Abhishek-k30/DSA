class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int sz1 = 0 , sz2 = 0, sz3  = 0, sz4 = 0;
        
        // all even
        for(int i = 0; i<n; i++){
            if(nums[i]%2==0)
                sz1++;
        }
        
        //all odd
        for(int i = 0; i<n; i++){
            if(nums[i]%2==1)
                sz2++;
        }
        
        // alternate odd even
        bool f = true;
        
        for(int i = 0; i<n; i++){
            if(f){
                if(nums[i]%2==1){
                    sz3++;
                    f = false;
                }
            }
            else{
                if(nums[i]%2 == 0){
                    sz3++;
                    f = true;
                }
            }
        }
        
        // alternate even odd
        
         f = true;
        
        for(int i = 0; i<n; i++){
            if(f){
                if(nums[i]%2 == 0){
                    sz4++;
                    f = false;
                }
            }
            else{
                if(nums[i]%2 == 1){
                    sz4++;
                    f = true;
                }
            }
        }
        
        
        return max({sz1, sz2, sz3, sz4});
    }
};