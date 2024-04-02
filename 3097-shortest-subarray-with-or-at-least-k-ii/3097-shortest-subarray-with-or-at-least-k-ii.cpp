class Solution {
public:
   void add(vector<int> &bits, int val){
        int idx=0;
       while(val>0){
           bits[idx]+= (val%2);
           val/=2;
           idx++;
       }
   }
    void remove(vector<int> &bits, int val){
        int idx=0;
       while(val>0){
           bits[idx]-= (val%2);
           val/=2;
           idx++;
       }
   }
    bool good(vector<int> &bits, int k){
        int cnt=0;
        for(int i=0; i<=31; i++){
             cnt+= (bits[i]? 1: 0)*(pow(2, i));
        }
        
        return(cnt>=k);
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> bits(32, 0);
        int l=0, ans=1e9;
        for(int r=0; r<n; r++){
            add(bits, nums[r]);
            while(l<r && good(bits, k)){
                
               if(good(bits, k)) ans=min(ans, r-l+1);
                remove(bits, nums[l]);
                l++;
            }
            
            if(good(bits, k))
            ans=min(ans, r-l+1);
            
            
        }
         
        ans=(ans !=1e9 ? ans : -1);
        return ans;
        
    }
};