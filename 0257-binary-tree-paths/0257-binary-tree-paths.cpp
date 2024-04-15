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
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
    void dfs(TreeNode* root, string s){
        if(!root->left && !root->right){
            s=insert(root->val, s);
            ans.push_back(s);
            return;
        }
        if(root->left)dfs(root->left, insert(root->val, s));
        if(root->right)dfs(root->right, insert(root->val,s));
    }
    string insert(int val, string s){
        if(s.size()==0)s+= to_string(val);
        else {
            s+="->";
            s+=to_string(val);
        }
        return s;
    }
};