class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n=nums.size();
        unordered_map<long long, int> m;
        for(int i=0; i<n; i++){
            m[nums[i]]=i;
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++ ){
                for(int k=j+1; k<n; k++){
                    long long val= (long long)target-(long long)nums[i]-(long long)nums[j]-(long long)nums[k];
                    if(m.find(val)!=m.end()){
                        int ind=m[val];
                        if(ind!=i && ind !=j && ind !=k){
                            vector<int> v={(int)nums[i], (int)nums[j], (int)nums[k], (int)val};
                            sort(v.begin(), v.end());
                            st.insert(v);
                        }
                    }
                }
            }
        }
            
        for(auto it: st)ans.push_back(it);
            
        return ans;
    }
};

// TC=O(n*n*n*logn), SC=O(n*n)