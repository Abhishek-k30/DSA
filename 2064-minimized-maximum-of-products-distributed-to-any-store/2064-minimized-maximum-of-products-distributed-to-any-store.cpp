class Solution {
public:
    bool check(int n, vector<int> v, int mid){
        int cnt=0;
        for(int i=0; i<v.size(); i++){
            cnt+=   v[i]/mid + (v[i]%mid!=0? 1 : 0);
        }
        if(cnt<=n)return true;
        return false;
         
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
         
        int low=1, high=1e5;
        int ans=high;
        while(low<=high){
            int mid= low + (high-low)/2;
            
            if(check(n, quantities, mid)){
                ans=mid;
                high=mid-1;
            }
            else low= mid+1;    
        }
        
        return ans;
    }
};