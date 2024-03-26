class Solution {
public:
    int fillCups(vector<int>& amount) {
         int sum=0, mx=0;
        for(int i=0; i<3; i++){
            mx=max(amount[i], mx);
            sum+=amount[i];
        }
        int rem= max(0, (sum-2*mx));
        int ans= mx +  rem/2 + rem%2;
        return ans;
    }
};