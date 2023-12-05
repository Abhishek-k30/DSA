class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
         set<vector<int>> st;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                
                int front=j+1;
                int rear=n-1;
                
                long sum = long(target) - long(nums[j]) - long(nums[i]);
                while(front<rear){
                    
                    long sm= (long)nums[front]+ (long)nums[rear];
                    
                    if(sum>sm){
                        front++;
                    }
                    else if(sum<sm){
                        rear--;
                    }
                    else{
                        vector<int> v={nums[i], nums[j], nums[front], nums[rear]};
                        st.insert(v);
                        front++;
                        rear--;
                    }
                    
                }
            }
        }
        
        for(auto it: st)ans.push_back(it);
        
        return ans;
    }
};