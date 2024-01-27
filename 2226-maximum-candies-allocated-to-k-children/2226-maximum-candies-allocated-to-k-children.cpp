class Solution {
public:
    bool check(vector<int>& candies, long long k, int div){
        long long cnt=0;
        for(int i=0; i<candies.size(); i++){
            cnt+= (candies[i]/div);
            if(cnt>=k)return true;
        }
        
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        
        long long sum=0;
        for(int i=0; i<n; i++)sum+=candies[i];
        
        if(sum<k)return 0;
         
        long long low=1, high=*max_element(candies.begin(), candies.end());
        int ans= 0;
        while(low<=high){
            int mid= low+ (high-low)/2;
            
            if(check(candies, k, mid) ){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        
        
        return ans;
        
        
        
        
        
    }
};