class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int> &temp, int start, int n, int k){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        
        for(int i=start; i<n; i++){
            temp.push_back(i+1);
            dfs(ans,temp,i+1, n, k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        if(n<k)return ans;
        dfs(ans,temp,0,n,k);
        return ans;
        
    }
};