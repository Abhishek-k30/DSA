class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> check;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]<0){
                int div= abs(nums[i])/value;
                if(abs(nums[i])%value!=0)div++;
                nums[i]+= div*value;
                //cout<<nums[i]<<" ";
            }
        }
        for(int i=0; i<n; i++){
            int rem;
                // if(abs(nums[i])>value){
                rem=nums[i]%value;
                cout<<rem<<" ";
                if(check.find(rem)==check.end())check[rem]++;
                else{
                    int nval= rem + check[rem]* value;
                    check[rem]++;
                    check[nval]++;
                }
              // }
            // else{
            //      if(check.find(rem)==check.end())check[rem]++;
            //     else{
            //         int nval= rem + check[rem]* value;
            //         check[rem]++;
            //         check[nval]++;
            //     }
            // }
            
            
            
        }
        // for(auto it: check){
        //     cout<<it.first<<" ";
        // }
        cout<<endl;
        for(int i=0; i<n; i++){
            if(check.find(i)==check.end())
                return i;
        }
        return n;
    }
};