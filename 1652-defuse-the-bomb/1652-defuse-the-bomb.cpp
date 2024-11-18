class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if(k==0){
            
            return ans;
        }
        else if(k>0){
            vector<int> pre(code.begin(), code.end());
            for(int i = 0; i<k; i++){
                pre.push_back(code[i]);
            }
            
            for(int i = 1; i<pre.size(); i++){
                pre[i]+= pre[i-1];
            }
            
            for(int i = 0; i<n; i++){
                int sum = pre[i+k]-pre[i];
                ans[i] = sum;
            }
            return ans;
        }
        else{
            
            vector<int> pre;
            
            for(int i = n+k; i<n; i++){
                pre.push_back(code[i]);
            }
            
            for(int i = 0; i<n; i++){
                pre.push_back(code[i]);
            }
            
            for(int i = pre.size()-2; i>=0; i--){
                pre[i]+= pre[i+1];
            }
            for(int i = 0; i<n; i++){
                int sum = pre[i] - pre[i+abs(k)];
                ans[i] = sum;
            }
            
            return ans;
        }
    }
};