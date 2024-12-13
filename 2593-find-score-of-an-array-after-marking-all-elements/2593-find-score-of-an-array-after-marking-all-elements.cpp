class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        multiset<pair<int, int>> st;
        
        for(int i = 0; i<n; i++){
            st.insert({nums[i], i});
        }
        
        long long sum = 0;
        
        while(!st.empty()){
            auto it = *st.begin();
            int minnum = it.first;
            int minidx = it.second;
            st.erase({minnum, minidx});
            
            sum+= 1LL*minnum;
            
            if(minidx-1>=0 && st.find({nums[minidx-1], minidx-1})!= st.end()){
                st.erase({nums[minidx-1], minidx-1});
            }
            
            if(minidx+1<n && st.find({nums[minidx+1], minidx+1})!=st.end()){
                st.erase({nums[minidx+1], minidx+1});
            }
        }
        
        return sum;
    }
};