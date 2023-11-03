class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        string p="Push",q="Pop";
        int ind=0;
        vector<string> ans;
        for(int i=1;i<=n; i++){
            if(ind==target.size())break;
            if(target[ind]==i){
                ans.push_back(p);
                ind++;
            }
            else{
                ans.push_back(p);
                ans.push_back(q);
            }
        }
        
        return ans;
        
    }
};

//TC=O(N), SC=O(N)