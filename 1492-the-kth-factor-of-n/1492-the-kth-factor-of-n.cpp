class Solution {
public:
    int kthFactor(int n, int k) {
//         vector<int> factors;
//         for(int i=1;i<=n; i++){
//             if(n%i==0)factors.push_back(i);
//         }
        
//         if(factors.size()<k)return -1;
//         return factors[k-1];
        //TC=O(N), SC=O(N);
        
        vector<int> frontFac, backFac;
        // Run a loop till sqrt(n);
        frontFac.push_back(1);
        for(int i=2; i*i<=n; i++){
            
            if(n%i==0){
                
            frontFac.push_back(i);
            
            if(i*i!=n){ // to prevent duplicate values;
                
                backFac.push_back(n/i);
                
            }}
        }
        
        for(int i=backFac.size()-1;i>=0; i--){
            frontFac.push_back(backFac[i]);
        }
        frontFac.push_back(n);
        
        if(frontFac.size()<k)return -1;
        return frontFac[k-1];
        
        
        
    }
};