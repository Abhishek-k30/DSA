class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        map<int, int> m;
        int sum=0;
        int cnt=0;
        for(int i=0; i<n; i++){
            sum+=(nums[i]==1 ? +1: -1);
            if(sum==0)cnt=max(cnt, i+1);
            if( m.find(sum)!=m.end()){
                cnt=max(cnt, i-m[sum]);
            }
            else{
                m[sum]=i;
            }
            
        }
        
        return cnt;
    }
};