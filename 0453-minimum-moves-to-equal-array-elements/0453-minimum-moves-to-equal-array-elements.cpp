#define ll long long
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        //sort(nums.begin(), nums.end());
        
//         2 5 67 89
//         89 92 67+87 89
//         89 89 92 154   +87
//         154 154 157 154  +65
//         154 154 154 157
//         157 157 157 157 +3
            
//         mx - mn
//         89 - 2
//         67+87 - 89
        
        //multiset<int> st(nums.begin(), nums.end());
        
        ll sum = accumulate(nums.begin(), nums.end(), (ll)0);
        ll mn = *min_element(nums.begin(), nums.end());
        
        return sum - mn*n;
        
        
        
    }
};