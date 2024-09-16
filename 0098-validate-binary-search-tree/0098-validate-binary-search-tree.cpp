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
private:
    bool check(TreeNode* root, long mn, long mx){
        if(!root){
            return true;
        }
        
        long val = root->val;
        if(val<mx && val>mn){
            return (check(root->left, mn, min(val, mx))) && 
                (check(root->right, max(mn, val), mx));
        }
        else return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return check(root, -1e14, 1e14);
    }
};