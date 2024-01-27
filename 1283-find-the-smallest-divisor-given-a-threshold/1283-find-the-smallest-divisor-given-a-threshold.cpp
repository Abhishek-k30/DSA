class Solution {
public:
    bool check(vector<int> v, int k , int div){
        int cnt=0;
        for(int i=0; i<v.size(); i++){
            cnt+= (v[i]/div);
            if(v[i]%div!=0)cnt++;
        }
        if(cnt<=k)return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1, high=*max_element(nums.begin(), nums.end());
        int ans=high;
        while(low<=high){
            int mid= low + (high-low)/2;
            
            if(check(nums, threshold, mid)){
                ans=mid;
                high=mid-1;
            }
            else low= mid+1;
        }
        
        return ans;
    }
};