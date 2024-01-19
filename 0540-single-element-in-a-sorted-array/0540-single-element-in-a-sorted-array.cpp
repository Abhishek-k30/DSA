class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int left=0, right=n-1;
        
        //Boundary Check
        if(right==0)
            return nums[0];
        else if(nums[0]!=nums[1])
            return nums[0];
        else if(nums[right]!=nums[right-1])
            return nums[right];
        
        while(left<=right){
            int mid= left + (right-left)/2;
            
            //Unique element Found
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
                return nums[mid];
            else if((mid%2==0 &&(nums[mid]==nums[mid+1])) 
                    || (mid%2==1 && nums[mid]==nums[mid-1]))
                left=mid+1;
            else right=mid-1;
                    
        }
        
        return -1;
    }
};

// O(logn), O(1)