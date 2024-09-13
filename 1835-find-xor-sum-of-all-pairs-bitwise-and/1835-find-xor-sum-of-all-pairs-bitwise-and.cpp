class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xorVal = 0;
        for(auto &it: arr2){
            xorVal^=it;
        }
        int ans = 0;
        for(auto&it: arr1){
            int cur = it&xorVal;
            ans^=cur;
        }
        return ans;
    }
};