class Solution {
public:
     long long check(vector<int>& piles, int speed){
         long long time=0;
        for(int i=0; i<piles.size(); i++){
            time+= ceil((double)(piles[i])/(double)(speed));
        }
        
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        long long low=1, high=*max_element(piles.begin(), piles.end());
        long long ans=high;
        while(low<=high){
            long long mid= low+ (high-low)/2;
            
            if(check(piles, mid)<=h){
                ans=min(ans, mid);
                high=mid-1;
            }
            else low=mid+1;
            
            
        }
        
        return ans;
    }
};