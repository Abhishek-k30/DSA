#define ll long long
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        ll n=nums.size();
        sort(nums.begin(), nums.end());
        ll sum=0;
        ll prev=0;
        ll idx=0;
        while(k>0 && idx<n ){
            ll len= nums[idx]-prev-1;
            if(len>k)len=k;
            if(len>0){
                ll start=prev;
                ll end= prev+len;
                sum+= (end*(end+1))/2 - (start*(start+1))/2;
                k-=len;
            }
            prev=nums[idx];
            idx++;
            
        }
        if(k>0){
            ll start=prev;
            ll end=prev+k;
            sum+= (end*(end+1))/2- (start*(start+1))/2;
        }
        
        return sum;
         
    }
};