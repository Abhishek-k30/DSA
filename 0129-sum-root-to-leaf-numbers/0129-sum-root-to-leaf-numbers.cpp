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
    int sum=0;
    int sumNumbers(TreeNode* root) {
        dfs(root, "");
        return sum;
    }
    void dfs(TreeNode* root, string s){
        if(root->left==NULL && root->right==NULL){
            s+=((root->val+'0'));
            sum+=stoi(s);
            return;
        }
        if(root->left)dfs(root->left, s+char((root->val)+ '0'));
        if(root->right)dfs(root->right, s+char((root->val)+ '0'));
    }
};