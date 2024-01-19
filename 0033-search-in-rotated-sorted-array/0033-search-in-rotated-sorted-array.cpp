class Solution {
public:
    int binarySearch(vector<int> v, int target, int st, int en){
        
        while(st<=en){
            int mid= st + (en-st)/2;
            
            if(v[mid]==target){
                return mid;
            }
            else if(v[mid]<target)
                st=mid+1;
            else en=mid-1;
        }
        
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0, r=n-1, init=nums[0];
 
 
        while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] > nums[r]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
        
        int k=l;
        
        
        int left= binarySearch(nums,target, 0, k-1);
        int right= binarySearch(nums, target, k, n-1);
        
        
         
        cout<<k<<" "<<left<<" "<<right<<endl;
        
        if(left==-1 && right==-1)
            return -1;
        else return max(left, right);
        
        
         
        
        
        
        
    }
};