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
    int sumOfLeftLeaves(TreeNode* root) {
       
        if(!root)return sum;
        leftSum(root);
        return sum; 
    }
    void leftSum(TreeNode* root){
        if(root->left!=NULL && !root->left->left && !root->left->right)sum+=root->left->val;
        if(root->left)leftSum(root->left );
        if(root->right)leftSum(root->right);
    }
};