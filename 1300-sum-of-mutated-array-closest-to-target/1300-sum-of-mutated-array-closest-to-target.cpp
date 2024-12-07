class Solution {
private:
    int check(int mid, vector<int>&arr, int target){
        int sum = 0;
        for(int i = 0; i<arr.size(); i++){
                if(arr[i]>mid) sum+=mid;
                else sum+= arr[i];
        }
        
        return abs(sum - target);
    }
public:
    int findBestValue(vector<int>& arr, int target) {
        int l = 0, r = 1e5;
        
        while(l<r){
            int mid = l + (r-l)/2;
            
            if(check(mid, arr, target) > check(mid+1, arr, target))
                l = mid+1;
            else r = mid;
        }
        
        return l;
    }
};