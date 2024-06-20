#define ll long long
class Solution {
private:
    bool good(vector<int> &nums, ll k, ll time){
        ll totalTime = time * k;
        
        for(auto &it :  nums){
            totalTime -=  min(time, (ll)it);
        }
        
        return totalTime<=0;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        ll sum = 0;
        int sz = batteries.size();
       // sort(batteries.begin(), batteries.end());
        for(int i = 0; i<sz; i++)
            sum+= 1LL*batteries[i];
        
        ll l = 0, r = sum;
        ll ans = 0;
        
       
        while(l<=r){
            ll mid = l + (r-l)/2;
            
            if(good(batteries, n, mid)){
                 
                ans = max(ans, mid);
                l = mid + 1;
            }
            else r = mid - 1;
        }
        
        
        return ans;
    }
};