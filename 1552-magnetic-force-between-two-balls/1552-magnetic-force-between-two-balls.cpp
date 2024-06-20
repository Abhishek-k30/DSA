class Solution {
private:
    bool good(vector<int>& nums, int m, int sz){
        int n = nums.size();
        int cnt = 1;
        int cur = nums[0];
        int prev = nums[0];
        int idx = 0;
        for(int i=0; i<n; i++){
             
            idx = lower_bound(nums.begin(), nums.end(), cur + sz)-nums.begin();
            if(idx<n && nums[idx]-cur>=sz){
               
                cur =  nums[idx];
                cnt++;
            }
            else break;
        }
        
        //cout<<cnt<<" "<<sz<<endl;
        return (cnt>=m);
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 0, r = 1e9;
        int ans = 0;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(good(position, m , mid)){
                ans = max(ans, mid);
                l = mid + 1;
            }
            else r = mid - 1;
        }
        
        //cout<<endl;
        return ans;
    }
};