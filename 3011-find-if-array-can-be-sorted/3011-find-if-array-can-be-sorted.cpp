class Solution {
bool check(int a, int b){
    int set_a =  __builtin_popcount(a);
    int set_b =  __builtin_popcount(b);
     
    return set_a == set_b;
}
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        
        for(int k = 0; k<n; k++){
        for(int i = 0; i<n-1; i++){
               int j = i+1;
                 if(nums[i]>nums[j] && check(nums[i], nums[j])){
                     swap(nums[i], nums[j]);
                 }
             
        }
        
        }
        for(int i = 0; i<n; i++)cout<<nums[i]<<" ";
        cout<<endl;
        
        return is_sorted(nums.begin(), nums.end());
        
    }
};