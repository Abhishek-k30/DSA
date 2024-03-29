class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
//         int l=0, ans=0, count=0;
//         for(int r=0; r<n; r++){
//             if(nums[r]%2==1){
//                 k--;
//                 count=0;
//             }
//             while(k==0){
//                 k+=nums[l]%2;
//                 count++;
//                 l++;
                
//             }
//             cout<<count<<" ";
//             ans+= count;
//         }
//         cout<<endl;
        
        //Method 2 converting all the nums as 0 or 1. For odd nums[idx]=1 else 0. And then finding the number of subarray sum==k
        
        
        unordered_map<int, int> m;
        int sum=0, ans=0;
        m[0]=1;
        for(int i=0; i<n; i++){
            sum+=nums[i]%2;
            if(m.find(sum-k)!=m.end()){
                ans+=m[sum-k];
            }
            m[sum]++;
        }
        
        return ans;
        
        
    }
};