class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int init=prices[0],b, ans=INT_MIN;
        for(int i=1; i<prices.size(); i++){
            if(prices[i-1]<init){
                init=prices[i-1];
            }
            b=prices[i]-init;
            ans=max(ans, b);
            
        }
        if(ans>=0)return ans;
        return 0;
    }
};

//TC=O(n), SC=O(1);