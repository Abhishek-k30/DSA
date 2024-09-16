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
    int minVal(TreeNode* root, int first){
        if(!root)return -1;
        if(root->val!=first)return root->val;
        
        int left = minVal(root->left, first);
        int right = minVal(root->right, first);
        
        if(left == -1)return right;
        if(right == -1)return left;
        
        return min(left, right);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        int ans = minVal(root, root->val);
        return ans;
    }
};