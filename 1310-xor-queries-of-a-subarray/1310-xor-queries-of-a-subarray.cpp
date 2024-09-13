class Solution {
private:
    vector<int> toBinary(int num){
        int i = 0;
        vector<int> bits(32,0);
        while(num){
            bits[i] = num%2;
            num/=2;
            i++;
        }
        return bits;
    }
    void xorValue(vector<int> &xor1, vector<int>&xor2){
        for(int i = 0 ; i<=31; i++){
            xor1[i] = xor1[i]^xor2[i];
        }
         
    }
    long long toDecimal(vector<int> &bits){
        long long value = 0;
        for(int i = 0; i<=31; i++){
            if(bits[i]){
                value+= (1LL<<i);
            }
        }
        return value;
    }
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<vector<int>> xorPrefix;
        for(int i = 0 ; i<n; i++){
            if(i == 0){
                vector<int> curBits = toBinary(arr[i]);
                xorPrefix.push_back(curBits);
            }
            else{
                vector<int> xor1 = toBinary(arr[i]);
                vector<int> xor2 = xorPrefix[i-1];
                xorValue(xor1,xor2);
                 
                xorPrefix.push_back(xor1);
            }
        }
        
        int q = queries.size();
        vector<int> ans(q);
        
        for(int i = 0; i<q; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            
            if(l == 0){
                ans[i] = toDecimal(xorPrefix[r]); 
            }
            else{
                vector<int> xor1 = xorPrefix[r];
                vector<int> xor2 = xorPrefix[l-1];
                
                xorValue(xor1, xor2);
                ans[i] = toDecimal(xor1);
            }
        }
        
        return ans;
    }
};