class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0, ans=0, count=0;
        for(int r=0; r<n; r++){
            if(nums[r]%2==1){
                k--;
                count=0;
            }
            while(k==0){
                k+=nums[l]%2;
                count++;
                l++;
                
            }
            cout<<count<<" ";
            ans+= count;
        }
        cout<<endl;
        
        return ans;
        
        
    }
};