/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
         if(!root)return ans;
         string temp="#";
        dfs(root, temp,0, targetSum);
        return ans;
    }
    void dfs(TreeNode* root, string s, int sum , int target){
        if(!root->left && !root->right){
            s+=(to_string(root->val));
             s+='#';
            sum+=root->val;
            if(sum==target){
                vector<int> t; 
                string val="";
                for(int i=1; i<s.size(); i++){
                    if(s[i]=='#'){
                        
                        if(val.size()>0)t.push_back(stoi(val));
                        val="";
                    }
                    else val+=s[i];
                }
                if(val.size()>0)t.push_back(stoi(val));
                ans.push_back(t);
            }
            return ;
        }
        if(root->left){
            string cur= to_string(root->val);
            dfs(root->left, s+cur+'#', sum+root->val,target);
        }
        if(root->right){
            string cur= to_string(root->val);
            dfs(root->right, s+cur+'#', sum+root->val,target);
        }
    }
    
    
    
};