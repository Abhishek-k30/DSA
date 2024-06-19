class Solution {
private:
    bool good(vector<int> &nums, int m , int k, int mid){
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]<=mid){
                cnt1++;
            }
            else cnt1 = 0;
            
            if(cnt1==k){
                cnt2++;
                cnt1 = 0;
            }
        }
        
        //cout<<cnt2<<" "<<mid<<endl;
        
        return (cnt2>=m);
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
         
        int mx = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = mx+2;
        int l = 1 , r = mx;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(good(bloomDay, m, k, mid )){
                ans = min(ans, mid);
                r = mid-1;
            }
            else l = mid+1;
        }
        
        //cout<<endl;
        return (ans != mx+2 ? ans : -1);
    }
};