class Solution {
public:
    string completeDigit(int nums, int digits){
        string cur = to_string(nums);
        int n = cur.size();
        for(int i = 0; i<digits-n; i++){
            cur = '0'+ cur;
        }
        return cur;
    }
    unordered_set<string> makeNumsCombination(int nums, int digits){
        string cur = completeDigit(nums, digits); 
        unordered_set<string> st;
        st.insert(cur);
        for(int i = 0; i<digits; i++){
            for(int j = i+1; j<digits; j++){
                if(cur[i]!=cur[j]){
                    swap(cur[i], cur[j]);
                    st.insert(cur);
                    
                    for(int i1 = 0; i1<digits; i1++){
                        for(int j1 = i1+1; j1<digits; j1++){
                            if(cur[i1]!=cur[j1]){
                                swap(cur[i1], cur[j1]);
                                st.insert(cur);
                                swap(cur[i1], cur[j1]);
                            }
                        }
                    }
                    swap(cur[i], cur[j]);
                }
            }
        }
        return st;
    }
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int digits = to_string(*max_element(nums.begin(), nums.end())).size();
        int ans = 0;
        unordered_map<string, int> mpp;
        for(int i = 0; i<n; i++){
            for(auto &it : makeNumsCombination(nums[i], digits)){
                if(mpp.find(it)!=mpp.end()){
                    ans+= mpp[it];
                }
            }
             mpp[completeDigit(nums[i], digits)]++;
        }
        return ans;
    }
};