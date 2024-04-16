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
    TreeNode* prev;
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newRoot= new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        int dep=depth-2;
        dfs(root, val, dep);
        return root;
    }
    void dfs(TreeNode* &root, int val, int dep){
        if(dep==0){
            TreeNode* left= new TreeNode(val);
            TreeNode* right= new TreeNode(val);
            TreeNode* extremeLeft=NULL;
            TreeNode* extremeRight=NULL;
            if(root->left)extremeLeft=root->left;
            if(root->right)extremeRight=root->right;
            
            root->left=left;
            root->right=right;
            
            left->left=extremeLeft;
            right->right=extremeRight;
            return;
        }
        if(root->left)dfs(root->left, val, dep-1);
        if(root->right)dfs(root->right, val, dep-1);
    }
};