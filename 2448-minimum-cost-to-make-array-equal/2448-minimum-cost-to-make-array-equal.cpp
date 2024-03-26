#define ll long long
class Solution {
public:
    long long check(ll mid, vector<int>& nums, vector<int>& cost ){
        ll sum=0;
        for(int i=0; i<nums.size(); i++){
            int value= abs(nums[i]-mid);
            sum+= 1LL* value* (cost[i]);
        }
        return sum;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll l=1, r=1e6;
        ll res=check(l, nums, cost);
        while(l<r){
            ll mid= l + (r-l)/2;
            ll mx1= check(mid, nums, cost);
            ll mx2= check(mid+1, nums, cost);
            res=min({res, mx1, mx2});
            if(mx1<mx2)r=mid;
            else l=mid+1;
        }
        
        
        return res;
        
    }
};