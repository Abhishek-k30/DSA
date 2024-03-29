class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int l=0, ans=0;
        multiset<int> st;
        for(int r=0; r<n; r++){
             st.insert(nums[r]);
            
            
             while(l<n && abs(*st.rbegin()-*st.begin())>limit){
                 // int cnt=st.count(nums[l]);
                 st.erase(st.find(nums[l]));
                 l++;
                  
            }
            
            
             
           
            ans=max(ans, r-l+1);
            
//             cout<<l+1<<" "<<r+1<<" "<<ans<<endl;
            
        }
        
       
        
        return ans;
    }
};