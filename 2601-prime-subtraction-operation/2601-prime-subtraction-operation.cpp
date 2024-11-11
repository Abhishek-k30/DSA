class Solution {
private:
    void SieveOfEratosthenes(int n,  vector<int> &ans)
{
     
    vector<bool> prime(n + 1, true);

  for (int p = 2; p * p <= n; p++) {


        

 
        if (prime[p] == true) {
             
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

   
    for (int p = 2; p <= n; p++)
        if (prime[p])
            ans.push_back(p);
}
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        vector<int> primes;
        SieveOfEratosthenes(1005, primes);
       
        
        for(int i = 0; i<n-1; i++){
            int cur = nums[i];
            int val = 0;
            int l = 0, r = primes.size()-1;
            for(int j = 0; j<r+1; j++){
                if(primes[j]<cur){
                    int x_v = cur-primes[j];
                    if(x_v<nums[i+1]){
                        if(i>0 && x_v>nums[i-1]){
                            val = max(val, primes[j]);
                        }
                        else if(i==0)
                        {
                            val = max(val, primes[j]);
                        }
                    }
                }
            }
            
            nums[i]-=val;
        }
        
        for(int i = 0; i<n-1; i++){
            //cout<<nums[i]<<" ";
            if(nums[i]>=nums[i+1])return false;
        }
        //cout<<endl;
        return true;
    }
};