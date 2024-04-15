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
    int ans=0;
    int longestUnivaluePath(TreeNode* root) {
        if(!root)return ans;
        dfs(root);
        return ans;
    }
    
    int dfs(TreeNode* root){
        int l=0, r=0;
        if(root->left)l=dfs(root->left);
        if(root->right)r=dfs(root->right);
        
        int leftHeight=0, rightHeight=0;
        if(root->left && root->left->val==root->val)leftHeight=l+1;
        if(root->right && root->right->val==root->val)rightHeight=r+1;
        
        ans=max(ans, leftHeight+ rightHeight);
        return max(leftHeight, rightHeight);
    }
};