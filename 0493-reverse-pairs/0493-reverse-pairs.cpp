#define ll long long
class Solution {
private:
    ll merge(vector<int> &nums, int low, int mid, int high){
        vector<int> temp;
        int left = low;
        int right = mid+1;
        ll cnt = 0;
        int j = right;
        for(int i = low; i<=mid; i++){
            while(j<=high && nums[i]> 2*(ll)nums[j]){
                j++;
            }
            cnt+= j-(mid+1);
        }
        while(left<=mid && right<= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                
                temp.push_back(nums[right]);
                right++;
            }
        }
        
        while(left<=mid)temp.push_back(nums[left++]);
        while(right<=high)temp.push_back(nums[right++]);
        
        for(int i = low; i<=high; i++){
            nums[i] = temp[i-low];
        }
        
        return cnt;
    }
public:
    ll mergeSort(vector<int>&nums, int low, int high){
        if(low>=high)return 0;
        int mid = (low + high)/2;
        ll cnt = 0;
        cnt+= mergeSort(nums, low, mid);
        cnt+= mergeSort(nums, mid+1, high);
        cnt+= merge(nums, low, mid, high);
        return cnt;
        
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};