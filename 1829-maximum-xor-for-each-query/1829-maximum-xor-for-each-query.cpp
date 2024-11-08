class Solution {
private:
    int maxXorValue(int n, int maxBits){
        vector<int> bits(maxBits, 0);
        for(int i = 0; i<maxBits; i++){
            if(n&(1<<i))bits[i] = 1;
        }
        
        int value = 0;
        for(int i = 0; i<bits.size(); i++){
            value+= (1<<i)*(bits[i]==0? 1: 0);
        }
        
        return value;
    }
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        
        vector<int> xorPre(n);
        xorPre[0] = nums[0];
        
        for(int i = 1; i<n; i++){
            xorPre[i] = xorPre[i-1]^nums[i];
        }
        
        vector<int> ans(n);
        for(int i = n-1; i>=0; i--){
            ans[n-i-1] = maxXorValue(xorPre[i], maximumBit);
        }
        
        return ans;
    }
};