class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int x = 0; x<=n; x++){
            int ind = lower_bound(nums.begin(), nums.end(), x)-nums.begin();
            cout<<ind<<endl;
            if(ind<n &&  (n-ind)==x)return  x;
        }
        cout<<endl;
        return -1;
    }
};