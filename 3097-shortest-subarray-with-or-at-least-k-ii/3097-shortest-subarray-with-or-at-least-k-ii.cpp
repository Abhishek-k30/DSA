class Solution {
public:
    void add(int nums,  vector<int> &bits){
        for(int i = 0; i<32; i++){
            bits[i]+= ((nums&(1<<i))!=0 ? 1 : 0);
        }
    }
    void remove(int nums , vector<int> &bits){
        for(int i = 0; i<32; i++){
            bits[i]-= ((nums&(1<<i))!=0 ? 1 : 0);
        }
    }
    bool good(int k, vector<int> &bits){
        long long cur = 0;
        for(int i = 0; i<32; i++){
            cur+= (long long)pow(2, i)*(bits[i] ? 1 : 0);
        }
        
        return cur>=k;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bits(32, 0);
        int l = 0, len = INT_MAX;
        
        for(int r = 0; r<n; r++){
            add(nums[r], bits);
            while(l<=r && good(k, bits)){
                len = min(len, r-l+1);
                remove(nums[l], bits);
                l++;
            }
            
             
        }
        if(len == INT_MAX)len = -1;
        return len;
    }
};