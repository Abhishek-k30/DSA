class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        for(int i=0; i<numbers.size(); i++){
            int req=target-numbers[i];
            int ind=lower_bound(numbers.begin(), numbers.end(), req)-numbers.begin();
            int up=upper_bound(numbers.begin(), numbers.end(), req)-numbers.begin();
            //cout<<ind<<" "<<up<<endl;
            
            if(ind!=numbers.size() &&i!=ind && numbers[i]+numbers[ind]==target){
                ans={min(i+1, ind+1), max(i+1, ind+1)};
                
            }
            else if(up!=numbers.size() && i!=up && numbers[i]+numbers[up]==target){
                ans={min(i+1, up+1), max(i+1, up+1)};
            }
        }
        return ans;
    }
};