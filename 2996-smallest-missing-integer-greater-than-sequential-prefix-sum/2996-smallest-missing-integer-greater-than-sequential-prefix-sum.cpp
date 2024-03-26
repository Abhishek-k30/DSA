class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        for(int i=0; i<n; i++)st.insert(nums[i]);
        int sum= nums[0];
        int mx=sum;
        for(int i=1; i<n; i++){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
            }
            else{
                mx=max(mx, sum);
                 break;
            }
        }
        
        mx=max(mx, sum);
         
        cout<<mx<<endl;
        while(st.find(mx)!=st.end()){
            mx++;
        }
        
        return mx;
    }
};