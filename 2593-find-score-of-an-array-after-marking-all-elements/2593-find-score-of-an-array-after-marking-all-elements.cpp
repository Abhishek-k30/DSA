class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        multiset<pair<int, int>> st;    //{minNum, idx}
        
        for(int i = 0; i<n; i++){
            st.insert({nums[i], i});
        }
        
        long long sum = 0;
        while(!st.empty()){
            auto it = *st.begin();
            int mini = it.first;
            int idx = it.second;
            
            sum += (1LL* mini);
            
            st.erase(st.begin());
            if(idx-1>=0 && idx-1<n && (st.find({nums[idx-1], idx-1})!= st.end()))
                st.erase(st.find({nums[idx-1], idx-1}));
            
            if(idx+1>=0 && idx+1<n && (st.find({nums[idx+1], idx+1})!= st.end()))
                st.erase(st.find({nums[idx+1], idx+1}));
 
        }
        
        return sum;
    }
};